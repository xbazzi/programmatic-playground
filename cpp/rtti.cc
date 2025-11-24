#include <cstdint>
#include <iostream>

uintmax_t x = 1;
struct S
{
    static const int x = 0; // declaration and in-class initialization
    static inline constexpr int y = 10;
    static int hi;
    // a definition outside of class is required if it is odr-used
};

static uint64_t bar;
static constexpr uint64_t foo	= 5;

		      
// const int& f(const int& r);
// bool b = false;
// int n = b ? (1, S::x) // S::x is not odr-used here
//           : f(S::x);  // S::x is odr-used here: a definition is required
		     
int main() 
{
	std::cout << typeid(x).name() << ", size(long long): " << sizeof(long long) << std::endl;
	(void)printf("Hello"), 5; // okay
	return 0;
}
