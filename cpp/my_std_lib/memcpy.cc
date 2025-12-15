#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <print>

void *my_memcpy(void *dst, const void *src, std::size_t n)
{
    unsigned char *to = static_cast<unsigned char *>(dst);
    const unsigned char *from = static_cast<const unsigned char *>(src);
    while (n >= 8)
    {
        *(to + 0) = *(from + 0);
        *(to + 1) = *(from + 1);
        *(to + 2) = *(from + 2);
        *(to + 3) = *(from + 3);
        *(to + 4) = *(from + 4);
        *(to + 5) = *(from + 5);
        *(to + 6) = *(from + 6);
        *(to + 7) = *(from + 7);
        to += 8;
        from += 8;
        n -= 8;
    }

    while (n--)
    {
        *to++ = *from++;
    }
    return dst;
}

auto main() -> int
{
    const char arr[]{"reallyLongStringYouWouldntEvenBelieveItCuzzin"};
    // Use char array instead of std::byte to avoid strict aliasing issues
    char *p = ::new (std::nothrow) char[100]();
    std::println("Before:\tp=\t\"{}\"",
                 p); // char and unsigned char have special exemption from strict aliasing rules (C++ standard §6.7.2.1)
    std::println("Before:\tarr=\t\"{}\"", arr);
    std::println("{}", sizeof(arr));

    my_memcpy(static_cast<void *>(p), static_cast<const void *>(arr), sizeof(arr)); // Include null terminator
    std::print("After:\tp=\t\"{}\"\n", p);
    ::delete[] (p);
    return EXIT_SUCCESS;
}