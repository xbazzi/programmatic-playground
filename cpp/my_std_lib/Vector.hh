#include <cstddef>
#include <memory>
#include <iterator>

template <typename T>
class Vector 
{

public:

    class Iterator;
    using iterator = Iterator;

    Vector();
    Vector(std::size_t newm_size);
    Vector(std::size_t newm_size, T data);
    Vector(std::size_t newm_size, T data, std::size_t cap);
    ~Vector();

    T& operator[](std::size_t index);

    void insert(T val);
    void remove();
    void double_capacity();
    size_t size() { return m_size; }
    size_t capacity() { return m_capacity; }
    iterator begin();
    iterator end();

private:
    T*     m_data;
    T*     p_last_el;
    size_t m_size;
    size_t m_capacity;
    std::unique_ptr<T[]> m_container;

public:
    class Iterator
    {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        Iterator(pointer ptr) : _ptr(ptr)
        {}

        reference operator*()  const { return *_ptr; }
        pointer   operator->() const { return _ptr; }

        iterator& operator++()
        {
            ++_ptr;
            return *this;
        }

        iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator operator-(int operand)
        {
            return this->_ptr - operand;
        }

        //iterator operator-(iterator other)
        //{
        //    return (&(this->get_ptr()) - &(other->get_ptr())) / sizeof(T);
        //}

        iterator operator+(int operand)
        {
            return this->_ptr + operand;
        }

        bool operator==(const Iterator& other)
        {
            return this->_ptr == other->_ptr;
        }

        bool operator!=(const Iterator& other)
        {
            return this->get_ptr() != other->get_ptr();
        }

        pointer get_ptr()
        {
            return _ptr;
        }

    private:
        pointer _ptr;
    };
};