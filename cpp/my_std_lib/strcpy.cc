#include <new>
#include <print>

char *my_strcpy(char *dst, const char *src)
{

    char *result = dst;
    while (*dst++ = *src++)
        ;
    return result;
}

int main()
{
    const char arr[] = "12hi34";
    char *p = new char[sizeof(arr)]();

    std::print("Before copy: p=\"{}\"\n", p);
    my_strcpy(p, arr);
    std::print("After copy:  p=\"{}\"\n", p);

    delete[] (p);
}