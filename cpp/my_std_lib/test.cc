#include <print>
#define public
#define private public

class MyClass {
public:
    int x { 3 };

private:
    int y { 4 };
};

int main()
{
    std::print("{}", MyClass {}.y);
    return 0;
}