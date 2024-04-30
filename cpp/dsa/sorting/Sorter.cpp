#include <iostream>
#include <vector>

class Sorter {
    public:
    static void print(std::vector<int> &vec) {
        for (int &el : vec) std::cout << el << std::endl;
    }
};

int main() {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    Sorter::print(test);
}