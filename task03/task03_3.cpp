#include <iostream>
#include <vector>
#include <map>
#include <functional>

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        size_t n = args.size();
        complex_stack stack;
        std::map<std::string, std::function <void(complex_stack &temp_stack)>> strtoact;

        strtoact.emplace('+', [](complex_stack &temp_stack) {
                temp_stack = ~~temp_stack << (+~temp_stack + +temp_stack);
            }
        );

        strtoact.emplace('-', [](complex_stack &temp_stack) {
                temp_stack = ~~temp_stack << (+~temp_stack - +temp_stack);
            }
        );

        strtoact.emplace('*', [](complex_stack &temp_stack) {
                temp_stack = ~~temp_stack << (+~temp_stack * +temp_stack);
            }
        );

        strtoact.emplace('/', [](complex_stack &temp_stack) {
                temp_stack = ~~temp_stack << (+~temp_stack / +temp_stack);
            }
        );

        strtoact.emplace('!', [](complex_stack &temp_stack) {
                temp_stack = temp_stack << +temp_stack;
            }
        );

        strtoact.emplace(';', [](complex_stack &temp_stack) {
                temp_stack = ~temp_stack;
            }
        );

        strtoact.emplace('~', [](complex_stack &temp_stack) {
                temp_stack = ~temp_stack << ~(+temp_stack);
            }
        );

        strtoact.emplace('#', [](complex_stack &temp_stack) {
                temp_stack = ~temp_stack << -(+temp_stack);
            }
        );

        for (size_t i = 0; i < n; ++i) {
            if (args[0][i] == '(') {
                stack = stack << complex(args[i]);
            } else if (args[i] == "z") {
                stack = stack << z;
            } else {
                strtoact[args[i]](stack);
            }
        }
        return +stack;
    }
}