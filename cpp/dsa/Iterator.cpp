#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class Iterator {
public:
    Iterator() : _vec{0} {}
    Iterator(std::vector<T> &vec) : _vec{vec} {}
        
    T* begin() {
         ptr = &_vec[0];
         return ptr;
    }

    T* end() {
         ptr = &_vec[_vec.size() - 1];
         return ptr;
    }

private:
    T *ptr;
    std::vector<T> _vec;
};

int main() {
    std::vector<int> test(2);
    test.push_back(1);
    test.push_back(5);

    const std::unique_ptr<Iterator<int>> it = std::make_unique<Iterator<int>>(test);
    std::cout << *it->begin() << std::endl;
    std::cout << *it->end() << std::endl;

}