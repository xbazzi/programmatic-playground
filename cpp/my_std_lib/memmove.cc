#include <cstdlib>

void *my_memmove(void *dst, const void *src, std::size_t n)
{
    if (!src or !dst or n == 0)
        return dst;
    unsigned char *to = static_cast<unsigned char *>(dst);
    const unsigned char *from = static_cast<const unsigned char *>(src);
    if (to < from)
    {
        while (n--)
        {
            *to++ = *from++;
        }
    }
    else if (from < to)
    {
        to += n;
        from += n;
        while (n--)
        {
            *--to = *--from;
        }
    }
    return dst;
}

#include <cassert>
#include <print>
#include <string_view>

int main()
{
    char arr[]{"himom"};
    std::print("Before copy: arr=\"{}\"\n", arr);
    my_memmove(arr + 2, arr, 2); // Copy "hi" to position 2
    std::print("After copy:  arr=\"{}\"\n", arr);
    assert(std::string_view(arr) == "hihim");
    return EXIT_SUCCESS;
}