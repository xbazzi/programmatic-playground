#include <cstdlib>
#include <new>
#include <print>

int main()
{
    int x = 10, y = 10;
    int* arr = ::new int[x * y]();
    int arr2[5];
    std::print("{}", sizeof(arr2));
    delete[] arr;
    return EXIT_SUCCESS;
}