#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

class Rectangle : public Figure
{
    double len = 0;
    double wid = 0;

  public:
    Rectangle(double l, double w) : len(l), wid(w) {}

    double
    get_square() const override
    {
        return len * wid;
    }

    static Rectangle *
    make(const std::string &params)
    {
        std::istringstream iss(params);
        double l, w;
        iss >> l >> w;
        Rectangle *obj = new Rectangle (l, w);
        return obj;
    }
};

class Square : public Figure
{
    double len = 0;

  public:
    Square(double l) : len(l) {}

    double
    get_square() const override
    {
        return len * len;
    }

    static Square *
    make(const std::string &params)
    {
        std::istringstream iss(params);
        double l;
        iss >> l;
        Square *obj = new Square(l);
        return obj;
    }
};

class Circle : public Figure
{
    double rad = 0;

  public:
    Circle(double r) : rad(r) {}

    double
    get_square() const override
    {
        return M_PI * rad * rad;
    }

    static Circle *
    make(const std::string &params)
    {
        std::istringstream iss(params);
        double r;
        iss >> r;
        Circle *obj = new Circle (r);
        return obj;
    }
};
