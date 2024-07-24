#include "Vector.hh"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <math.h>

template <typename T>
Vector<T>::Vector() :
    m_size{0}, m_capacity{1}, m_container(std::make_unique<T[]>(1)),
    p_last_el{m_container.get()}
{}

template <typename T>
Vector<T>::Vector(std::size_t newm_size) : 
    m_container{std::make_unique<T[]>(m_capacity)}, m_size{newm_size}, 
    m_capacity{newm_size}, p_last_el{m_container.get() + newm_size - 1}
{}

template <typename T>
Vector<T>::Vector(std::size_t newm_size, T data) : 
    m_container{std::make_unique<T[]>(m_capacity)}, m_data{data},
    m_size(newm_size), p_last_el{m_container.get() + newm_size - 1}
{}

template <typename T>
Vector<T>::Vector(std::size_t newm_size, T data, std::size_t cap) : 
    m_container{std::make_unique<T[]>(m_capacity)}, m_data{data},
    m_size(newm_size), m_capacity{cap}, 
    p_last_el{m_container.get() + newm_size - 1}
{}

template <typename T>
Vector<T>::~Vector() = default;

template <typename T>
T& Vector<T>::operator[](std::size_t index)
{
    return m_container[index];
}

template <typename T>
void Vector<T>::double_capacity()
{
    m_capacity *= 2;
    std::unique_ptr<T[]> new_m_container = std::make_unique<T[]>(m_capacity);
    for (std::size_t i = 0; i < m_size; i++)
    {
        new_m_container[i] = std::move(m_container[i]);
    }
    m_container = std::move(new_m_container);
}

template <typename T>
void Vector<T>::insert(T val)
{
    if (m_size == m_capacity)
    {
        double_capacity();
    }
    m_container[m_size] = val;
    p_last_el = m_container.get() + m_size;
    ++m_size;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() 
{
    return iterator(m_container.get());
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() 
{
    return iterator(m_container.get() + m_size);
}

int main()
{
    Vector<int> vec{};
    std::cout << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << std::endl;
    vec.insert(1);
    vec.insert(2);
    vec.insert(3);
    vec.insert(4);
    vec.insert(5);
    vec.insert(6);
    vec.insert(7);
    vec.insert(8);
    vec.insert(9);

    ///@todo implement for each loops
    //for (int num : vec)
    //{
    //    std::cout << num << " ";
    //} std::cout << std::endl;
    
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    } std::cout << std::endl;
    std::cout << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << std::endl;
    bool result = &(*(vec.end())) == &(*(vec.begin()));
    Vector<int>::Iterator diff = vec.end() - 3;
    std::cout << "This should be false: " << std::boolalpha << result << std::endl;
    std::cout << "*(vec.end() - 3) = " << *diff << std::endl;
}