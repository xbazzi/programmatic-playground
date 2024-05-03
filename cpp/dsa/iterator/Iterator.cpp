#include <iostream>
#include <vector>

class IntIterator {
public:
    IntIterator(std::vector<int> &vec) : _vec(vec) {}
        
    int *begin() {
         ptr = &_vec[0];
         return ptr;
    }

    int *end() {
         ptr = &_vec[_vec.size() - 1];
         return ptr;
    }

private:
    int *ptr;
    std::vector<int> _vec;
};


int main() {
    std::vector<int> test(2);
    test.push_back(1);
    test.push_back(5);

    IntIterator *it = new IntIterator(test);
    std::cout << *it->begin() << std::endl;
    std::cout << *it->end() << std::endl;

}