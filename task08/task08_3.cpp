#include <iostream>

class S {
    int val = 0;
    bool flag = false;

public:
    S() {
        if (!(std::cin >> val)) {
            val = 0;
        }
    }

    S(S&& other) noexcept {
        val = other.val;
        if (std::cin >> other.val) {
            val += other.val;
        } else {
            other.val = val;
            other.flag = true;
            val = 0;
        }
    }

    ~S() {
        if (val && flag) {
            std::cout << val << std::endl;
        }
    }

    explicit operator bool() const {
        return val != 0;
    }
};
