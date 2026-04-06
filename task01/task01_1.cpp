#include <iostream>

class Sum
{
    int a, b;

  public:
    Sum(int a_, int b_) : a(a_), b(b_) {}

    Sum(Sum obj_a, int b_) : a(obj_a.get()), b(b_) {}

    Sum(int a_, Sum obj_b) : a(a_), b(obj_b.get()) {}

    int
    get() const
    {
        return a + b;
    }
};
