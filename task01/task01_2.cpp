#include <iostream>

class A
{
    int a;
    bool flag = false;

  public:
    A() { std::cin >> a; }

    A(const A &obj)
    {
        std::cin >> a;
        a = a + obj.a;
        flag = true;
    }

    ~A()
    {
        if (flag) {
            std::cout << a << std::endl;
        }
    }
};
