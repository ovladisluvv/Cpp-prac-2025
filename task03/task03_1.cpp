#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

namespace numbers
{
class complex
{
    double real = 0.0;
    double imag = 0.0;

  public:
    complex() : real(0.0), imag(0.0){}

    complex(const double real_) : real(real_), imag(0.0){}

    complex(const double real_, const double imag_) : real(real_), imag(imag_){}

    explicit complex(const std::string &str)
    {
        char temp;
        std::istringstream sis(str);
        sis >> temp >> real >> temp >> imag >> temp;
    }

    double
    re() const
    {
        return real;
    }

    double
    im() const
    {
        return imag;
    }

    double
    abs2() const
    {
        return real * real + imag * imag;
    }

    double
    abs() const
    {
        return sqrt(abs2());
    }

    std::string
    to_string() const
    {
        std::ostringstream sos;
        sos << '(' << real << ',' << imag << ')';
        return sos.str();
    }

    complex &
    operator+=(const complex &other)
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    complex &
    operator-=(const complex &other)
    {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    complex &
    operator*=(const complex &other)
    {
        double new_real = real * other.real - imag * other.imag;
        double new_imag = real * other.imag + imag * other.real;
        real = new_real;
        imag = new_imag;
        return *this;
    }

    complex &
    operator/=(const complex &other)
    {
        double new_real = (real * other.real + imag * other.imag) / other.abs2();
        double new_imag = (imag * other.real - real * other.imag) / other.abs2();
        real = new_real;
        imag = new_imag;
        return *this;
    }

    friend complex
    operator+(const complex &num1, const complex &num2)
    {
        return complex(num1.real + num2.real, num1.imag + num2.imag);
    }

    friend complex
    operator-(const complex &num1, const complex &num2)
    {
        return complex(num1.real - num2.real, num1.imag - num2.imag);
    }

    friend complex
    operator*(const complex &num1, const complex &num2)
    {
        return complex(num1.real * num2.real - num1.imag * num2.imag, num1.real * num2.imag + num1.imag * num2.real);
    }

    friend complex
    operator/(const complex &num1, const complex &num2)
    {
        return complex((num1.real * num2.real + num1.imag * num2.imag) / num2.abs2(),
                       (num1.imag * num2.real - num1.real * num2.imag) / num2.abs2());
    }

    friend complex
    operator~(const complex &num)
    {
        return complex(num.real, -num.imag);
    }

    friend complex
    operator-(const complex &num)
    {
        return complex(-num.real, -num.imag);
    }
};
} // namespace numbers
