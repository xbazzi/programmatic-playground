#include "Vector.hh"
#include <iostream>
#include <cstdlib>

template <typename T>
Vector<T>::Vector() :
    size{0}, capacity{1}, container(std::make_unique<T[]>(1)),
    p_last_el{container.get()}
{}

template <typename T>
Vector<T>::Vector(std::size_t new_size) : 
    container{std::make_unique<T[]>(capacity)}, size{new_size}, 
    capacity{new_size}, p_last_el{container.get() + new_size - 1}
{}

template <typename T>
Vector<T>::Vector(std::size_t new_size, std::size_t cap) : 
    container{std::make_unique<T[]>(capacity)}, size(new_size),
    capacity{cap}, p_last_el{container.get() + new_size - 1}
{}

template <typename T>
Vector<T>::~Vector() = default;

template <typename T>
T& Vector<T>::operator[](std::size_t index)
{
    return container[index];
}

template <typename T>
void Vector<T>::double_capacity()
{
    capacity *= 2;
    std::unique_ptr<T[]> new_container = std::make_unique<T[]>(capacity);
    //new_container = realloc(container, sizeof(T) * capacity)
    for (std::size_t i = 0; i < size; i++)
    {
        new_container[i] = std::move(container[i]);
    }
    container = std::move(new_container);
}

template <typename T>
void Vector<T>::insert(T val)
{
    if (size == capacity)
    {
        double_capacity();
    }
    container[size] = val;
    p_last_el = container.get() + size;
    ++size;
}

int main()
{
    Vector<int> vec{};
    std::cout << vec.size << ", " << vec.capacity << std::endl;
    vec.insert(2);
    vec.insert(6);
    std::cout << vec[0] << ", " << vec[1] << std::endl;
}