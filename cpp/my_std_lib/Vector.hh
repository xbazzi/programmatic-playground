#include <cstddef>
#include <memory>

template <typename T>
class Vector {

using iterator = std::iterator;
public:

    Vector();
    Vector(std::size_t new_size);
    Vector(std::size_t new_size, std::size_t cap);
    ~Vector();

    T& operator[](std::size_t index);

    void insert(T val);
    void remove();
    void double_capacity();

    T* p_last_el;
    size_t capacity;
    size_t size;
    std::unique_ptr<T[]> container;
};