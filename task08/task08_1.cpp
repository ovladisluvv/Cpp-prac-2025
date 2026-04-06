#include <iostream>
#include <string>
#include <exception>

class Printer
{
    std::string str;

  public:
    Printer(const std::string &s) : str(s) {}
    ~Printer() { std::cout << str << std::endl; }
};

void
read_str()
{
    std::string cur_str;
    if (std::cin >> cur_str) {
        Printer next(cur_str);
        read_str();
    } else {
        throw std::runtime_error("Stop");
    }
}

int
main()
{
    try {
        read_str();
    } catch (...) {
    }
}
