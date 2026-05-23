#include <cstdio>


template <class Derived>
class Parent
{
public:
    void foo() 
    {
        static_cast<Derived*>(this)->foo();
    }

};

class Child : public Parent<Child>
{
public:
    void foo()
    {
        printf("This is derived\n");
    }
};

class UglyChild : public Parent<UglyChild>
{
public:
    void foo()
    {
        printf("Hi, I'm aesthetically challenged\n");
    }
};

int main() 
{
    Child c;
    UglyChild u;
    c.foo();
    u.foo();
}