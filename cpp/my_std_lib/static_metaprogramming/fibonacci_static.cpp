/// Author:  Alexander Bazzi
/// Description: Chooses between a for-loop and a while-loop based on
///              a boolean set using compile-time evaluation and template 
///              metaprogramming.

#include <iostream>

template<int N>
struct Fibonacci
{
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0>
{
    static const int value = 0;
};

template<>
struct Fibonacci<1>
{
    static const int value = 1;
};

int main()
{
    std::cout << std::fixed << "Fibonacci(10) = " << Fibonacci<10>::value << std::endl;
}