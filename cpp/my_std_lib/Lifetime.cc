#include <iostream>
#include <concepts>
#include <memory>

namespace life {
    class Lifetime {
    public:
        Lifetime()
        {
            std::printf("Default constructed.\n");
        }

        Lifetime(Lifetime& other_lifetime)
        {
            std::cout << "Copy constructed." << std::endl;
        }

        Lifetime(Lifetime&& other_lifetime)
        {
            std::cout << "Move constructed." << std::endl;
        }

        ~Lifetime() noexcept
        {
            std::puts("Destroyed.");
        }
    };
}; // end namespace life

int main()
{
    life::Lifetime a;
    life::Lifetime b = std::move(a);
    return 0;
}
