#include <cstddef>
template <typename T>
class Vector {

    Vector();

    Vector(std::size_t new_size);

    ~Vector();

    size_t capacity;
    size_t size;
    T a[size];
};