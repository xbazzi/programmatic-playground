#include <iostream>
#include <vector>

class Sorter {
    public:

    static void insertionSort(std::vector<int> &vec) {
        int n = vec.size();
        for (int i = 1; i < n; i++) {
            int key = vec[i];
            int j = i - 1;

            // Move elements of vec[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j = j - 1;
            }
            vec[j + 1] = key;
            }
    }

    static void print(std::vector<int> &vec) {
        for (int &el : vec) std::cout << el << std::endl;
    }
};

int main() {
    std::vector<int> test;
    test.push_back(9);
    test.push_back(4);
    test.push_back(2);
    test.push_back(7);
    test.push_back(1);
    Sorter::print(test);

    std::cout << std::endl;

    Sorter::insertionSort(test);
    Sorter::print(test);
}