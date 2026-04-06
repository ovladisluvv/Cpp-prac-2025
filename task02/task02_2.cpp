#include <iostream>

class C
{
    int val;

  public:
    C(int val_ = 0) { val = val_; }
    C(double val_) { val = static_cast<int>(val_); }
    C(const C &other) { val = other.val; }
    C(const C *p) { val = p->val; }
    C(const C &v1, const C &v2) {}
    ~C(){};

    const C
    operator~()
    {
        return C(~val);
    }

    C &
    operator++()
    {
        ++val;
        return *this;
    }

    const C
    operator*(const C &other)
    {
        return C(val * other.val);
    }

    operator int() const { return val; }
};
