#include <cstdlib>
#include <stdexcept>

struct Test {
    Test() { throw std::runtime_error("u trippin."); }
};

auto main() -> int
{
    Test* t = ::new (std::nothrow) Test {};
    return EXIT_SUCCESS;
}
