#include <string>

class Figure
{
  public:
    virtual ~Figure() = default;

    virtual bool equals(const Figure *figure) const {
        if (!figure) {
            return false;
        }

        return true;
    }
};

class Rectangle : public Figure
{
    int len, wid;
    public:

    Rectangle(int l, int w) : len(l), wid(w) {}

    bool
    equals(const Figure *figure) const override
    {
        if (!figure) {
            return false;
        }

        const Rectangle *other = dynamic_cast<const Rectangle *>(figure);
        return other && (len == other->len) && (wid == other->wid);
    }
};

class Triangle : public Figure
{
    int a, b, c;
    public:

    Triangle(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}

    bool
    equals(const Figure *figure) const override
    {
        if (!figure) {
            return false;
        }

        const Triangle *other = dynamic_cast<const Triangle *>(figure);
        return other && (a == other->a) && (b == other->b) && (c == other->c);
    }
};
