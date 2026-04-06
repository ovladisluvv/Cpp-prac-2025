#include <iostream>
#include <cstdint>

// Recursive function named "func" throws exceptions as objects of class "Result" according to the rules from the task
// conditions. If not, it keeps calling itself until an exception is thrown according to the rules from the task
// conditions.
// The meaning of the function: if k == 0, it's a + b; if k == 1, it's a * b; if k == 2, it's a ^ b (^ as power of, not
// XOR) etc.

class Result : public std::exception
{
    uint64_t res;

  public:
    Result(uint64_t r) : res(r) {}

    uint64_t
    get_res()
    {
        return res;
    }
};

void
func(uint64_t a, uint64_t b, uint32_t k)
{
    if (!k) {
        throw Result(a + b);
    } else if (b == 1) {
        throw Result(a);
    }

    try {
        func(a, b - 1, k);
    } catch (Result &ex) {
        func(a, ex.get_res(), k - 1);
    }
}

int
main()
{
    uint64_t a, b;
    uint32_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result &ex) {
            std::cout << ex.get_res() << std::endl;
        }
    }
}
