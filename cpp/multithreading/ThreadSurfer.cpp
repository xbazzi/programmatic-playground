#include <iostream>
#include <thread>
#include <future>

class ThreadSurfer {
public:
    ThreadSurfer() {}
    ~ThreadSurfer() {}

    void readData() {
        std::cout << std::fixed << _data << std::endl;
    }

private:
    int data = 0;
};