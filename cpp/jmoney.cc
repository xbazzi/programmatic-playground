#include <cstdint>
#include <iostream>
#include <assert.h>


void add_two(uint16_t* ptr)
{
    // uint16_t c = a + 2;
    *ptr = *ptr + 6;
}

int main() {
    uint16_t a = 10;
    //             3210 <- 2^  
    // ptr_to_a: 0x000FF2 -> 00001010 |
    // static_assert(a, 10);
    uint16_t* ptr_to_a = &a;
    std::cout << a << " and its address is " << &a << std::endl;
    add_two(ptr_to_a);
    std::cout << " new a = " << *ptr_to_a << std::endl;
    free(ptr_to_a);
    ptr_to_a = nullptr;

    return 0;
}