#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>
#include <future>

std::mutex cout_mutex; // Global mutex for std::cout syncing

template <typename VINType>
class Vehicle
{
    /*
    * Public member methods
    */
    public:

    /*
    * Constructor
    */
    Vehicle(VINType vin, int miles) 
        : _vin{ vin },
          _odometer { miles }
    {
    }

    void displayOdometer()
    {
        std::lock_guard<std::mutex> locked(odometer_mutex);
        {
            std::lock_guard<std::mutex> cout_locked(cout_mutex);
            std::cout << "This vehicle has " << _odometer 
                    << " miles." << std::endl;
        }
    }

    void displayVIN()
    {
        std::lock_guard<std::mutex> locked(odometer_mutex);
        {
            std::lock_guard<std::mutex> cout_locked(cout_mutex);
            std::cout << "VIN: " << _vin << std::endl;
        }
    }

    void updateOdometer(const int milesPerSecond, const int seconds)
    {
        {
            std::lock_guard<std::mutex> cout_locked(cout_mutex);
            std::cout << "Updating odometer for " << seconds << " seconds"
                    << " at " << milesPerSecond << " miles/second."
                    << std::endl;
        }

        for (int i = 0; i < seconds; i++)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            {
                std::lock_guard<std::mutex> locked(odometer_mutex);
                _odometer += milesPerSecond;
            }
            displayOdometer();
        }
    }

    /*
    * Private member variables
    */
    private:

    int _odometer;
    VINType _vin;

    static std::mutex odometer_mutex;
};

// Global variables
template <typename VINType>
std::mutex Vehicle<VINType>::odometer_mutex; // Static member variable definition

int main()
{
    // instantiate vehicle object via a smart pointer
    std::unique_ptr<Vehicle<std::string>> vehicle = std::make_unique<Vehicle<std::string>>("1337-CODE", 50000);
    auto vehicle2 = std::make_unique<Vehicle<int>>(1337, 25000);

    std::promise<void> odometerUpdateDone;
    std::future<void> future = odometerUpdateDone.get_future();

    // call member functions on separate threads
    std::thread displayThread(&Vehicle<std::string>::displayOdometer, vehicle.get());

    int milesPerSecond = 11;
    int totalMiles = 5;
    std::thread updateThread([&]() 
    { 
        vehicle->updateOdometer(milesPerSecond, totalMiles); 
        odometerUpdateDone.set_value();
    });

    future.wait(); // Wait for the odometer to finish updating before printing VIN
    std::thread displayVINThread(&Vehicle<int>::displayVIN, vehicle2.get()); // Print VIN

    // Join side threads with main thread
    displayThread.join();
    updateThread.join();
    displayVINThread.join();

    return 0;
}