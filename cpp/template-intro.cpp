#include <iostream>

template <typename T> const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

int main()
{
    const int a = 0, b = 2;
    std::cout << max<int>(a, b) << std::endl;
    std::cout << max<long double>(4.56, 434.5) << std::endl;
    std::cout << max<char>('a', 'b') << std::endl;
    std::cout << max<bool>(true, false) << std::endl;
    std::cout << max<uint>(1, 0) << std::endl;
    return 0;
}
