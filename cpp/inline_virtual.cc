#include <cstdlib>
#include <print>

struct SomeClass {
    virtual void foo()
    {
        std::print("SomeClass::foo");
    }
};

struct AnotherClass : public SomeClass {
    inline void foo() override
    {
        std::print("AnotherClass::foo");
    }
};

int main()
<%
    AnotherClass {}.foo();
    // ac.foo();

    return EXIT_SUCCESS;
%>