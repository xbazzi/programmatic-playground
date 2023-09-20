#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>

class Vehicle
{
    /*
    * Public member methods
    */
    public:

    /*
    * Constructor
    */
    Vehicle(const char* vin, int miles) 
        : _vin{vin},
          _odometer {miles}
    {
    }

    void displayOdometer()
    {
        std::lock_guard<std::mutex> locked(odometer_mutex);
        std::cout << "This vehicle has " << _odometer << " miles." << std::endl;
    }

    void updateOdometer(const int milesPerSecond, const int seconds)
    {
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

    void setOdometer(const int miles)
    {
        _odometer = miles;
    }

    /*
    * Private member variables
    */
    private:

    int _odometer;
    const char* _vin;
    static std::mutex odometer_mutex;
};

std::mutex Vehicle::odometer_mutex;

int main()
{
    // instantiate vehicle object via a smart pointer
    std::unique_ptr<Vehicle> vehicle;
    vehicle = std::make_unique<Vehicle>("1337", 50000);

    // call member functions on separate threads
    std::thread displayThread(&Vehicle::displayOdometer, vehicle.get());
    std::thread updateThread(&Vehicle::updateOdometer, vehicle.get(), 10, 5);

   // // call member functions on main thread, behavior is undefined
   // vehicle->displayOdometer();
   // int someMileage = 1;
   // vehicle->setOdometer(someMileage);
    
    // join side threads with main thread
    displayThread.join();
    updateThread.join();

    return 0;
}