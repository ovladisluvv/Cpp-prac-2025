#include <iostream>
#include <cstring>

class BinaryNumber
{
    std::string bin_num;

  public:
    BinaryNumber(const std::string &s) : bin_num(s){}

    operator std::string() const { return bin_num; }

    const BinaryNumber &
    operator++()
    {
        for (int i = bin_num.length(); i >= 0; --i) {
            if (bin_num[i] == '0') {
                bin_num[i] = '1';
                return *this;
            }
            bin_num[i] = '0';
        }
        bin_num.insert(bin_num.begin(), '1');
        return *this;
    };
};
