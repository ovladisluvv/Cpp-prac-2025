#include <iostream>
#include <string>
#include <stack>
#include <set>

int
main()
{
    std::stack<std::string> polrn;
    const std::set<char> OPS = {'+', '-', '*', '/'};
    char cur_char;

    while (std::cin >> cur_char) {
        if (OPS.contains(cur_char)) {
            std::string left = polrn.top();
            polrn.pop();
            std::string right = polrn.top();
            polrn.pop();
            polrn.push("(" + right + cur_char + left + ")");
        } else {
            std::string new_var(1, cur_char);
            polrn.push(new_var);
        }
    }

    std::cout << polrn.top() << std::endl;
}
