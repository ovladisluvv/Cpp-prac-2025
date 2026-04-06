#include <iostream>

// S -> aSd | A
// A -> bAc | B
// B -> bc

void
B()
{
    std::cout << "bc";
}

void
A(int k)
{
    if (k == 1) {
        B();
        return;
    }

    std::cout << 'b';
    A(k - 1);
    std::cout << 'c';
}

void
S(int n, int k)
{
    if (!n) {
        A(k);
        return;
    }

    std::cout << 'a';
    S(n - 1, k);
    std::cout << 'd';
}

void
start(int cur_len, int k)
{
    if (!cur_len) {
        return;
    }
    S(cur_len, k - cur_len);
    std::cout << std::endl;
    start(cur_len - 1, k);
}

int
main()
{
    int k;
    std::cin >> k;

    if (!(k % 2)) {
        start(k / 2 - 1, k / 2);
    }
}
