#include <iostream>
#include <vector>

namespace sort {
class Sorter {
public:
    /// @brief  Print all elements in the vector.
    /// @tparam T
    /// @param  vec
    template <typename T>
    static void print(std::vector<T>& vec)
    {
        for (int& el : vec)
            std::cout << el << " ";
        std::cout << std::endl;
    }

    /// @brief  Sort the vector using insertion sort.
    /// @tparam T
    /// @param  vec
    /// @todo   Develop a solid understanding of this implementation.
    template <typename T>
    static void insertionSort(std::vector<T>& vec)
    {
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

    /// @brief  Sort the vector with selection sort.
    /// @tparam T
    /// @param  vec
    template <typename T>
    static void selectionSort(std::vector<T>& vec)
    {
        for (auto currIt = vec.begin(); currIt != vec.end(); currIt++) {
            auto minIt = _smallest<T>(currIt, vec.end());
            if (minIt != currIt)
                std::iter_swap(minIt, currIt);
        }
    }

    template <typename T>
    static std::vector<T> quickSort(std::vector<T>& vec)
    {
        if (vec.size() < 2)
            return vec;
        int n = vec.size();
        std::vector<T> smaller;
        std::vector<T> equal;
        std::vector<T> larger;
        int pivotValue = vec[0];
        for (const T& item : vec) {
            if (item < pivotValue) {
                smaller.push_back(item);
            } else if (item == pivotValue) {
                equal.push_back(item);
            } else {
                larger.push_back(item);
            }
        }
        smaller = quickSort(smaller);
        larger = quickSort(larger);

        std::vector<T> sortedVec;
        sortedVec.insert(sortedVec.end(), smaller.begin(), smaller.end());
        sortedVec.insert(sortedVec.end(), equal.begin(), equal.end());
        sortedVec.insert(sortedVec.end(), larger.begin(), larger.end());

        return sortedVec;
    }

private:
    /// @brief  Calculate the smallest element in the vector
    /// @tparam T
    /// @param  it Starting position iterator
    /// @param  end Final position iterator
    /// @return Smallest element in the range between iterators
    template <typename T>
    static typename std::vector<T>::iterator _smallest(typename std::vector<T>::iterator it, typename std::vector<T>::iterator end)
    {
        typename std::vector<T>::iterator smallest_it = it;
        for (; it != end; it++) {
            if (*it < *smallest_it) {
                smallest_it = it;
            }
        }
        return smallest_it;
    }
};
} // End of namespace sorter

int main()
{
    std::vector<int> test;
    test.push_back(5);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);
    sort::Sorter::print(test);

    test = sort::Sorter::quickSort(test);
    sort::Sorter::print(test);
}