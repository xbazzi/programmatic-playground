#include <iostream>

class A {
public:
    A()
    {
        method();
    }

    virtual void method()
    {
       std::cout << 1;
    }
};

class B : public A {
public:
    virtual void method()
    {
        std::cout << "2";
    }
};

int main ()
{
    B b;
    A *a;
    a = static_cast<A*>(&b);
    std::cout << std::endl;
    a->method();
    //void (A:: * pcat)();
    //pcat = &A::method;
    //(b.*pcat)();
    return 0;
}
