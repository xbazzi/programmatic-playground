#include <cstdlib>

constexpr void* my_memmove(void* dst, const void* src, std::size_t n)
{
    if (src == dst or !(src and dst))
        return nullptr;
    unsigned char* to = static_cast<unsigned char*>(dst);
    const unsigned char* from = static_cast<const unsigned char*>(src);
    while (n--) {
        if (to and from and from != to)
            *to++ = *from++;
    }
    return dst;
}

#include <cassert>
#include <print>
#include <string_view>
int main()
{
    char arr[] { "himom" };
    std::print("Before copy: arr=\"{}\"\n", arr);
    my_memmove(arr + 2, arr, 2);
    std::print("After copy:  arr=\"{}\"\n", arr);
    assert(std::string_view(arr) == "hihim");
    return EXIT_SUCCESS;
}