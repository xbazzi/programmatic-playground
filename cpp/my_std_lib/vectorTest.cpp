#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec(10);
    size_t max_size = vec.max_size();
    std::cout << std::scientific << max_size << std::endl;
    std::cout << alignof(char) << std::endl;
}
