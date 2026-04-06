#include <iostream>

class Reverse
{
    unsigned long long num;
    bool flag = false;

  public:
    Reverse()
    {
        if (std::cin >> num) {
            flag = true;
            Reverse next;
        }
    }

    ~Reverse()
    {
        if (flag) {
            std::cout << num << ' ';
        }
    }
};

int
main()
{
    Reverse start;
    return 0;
}
