#include <chrono>
#include <iostream>
#include <string>
#include "coins.h"
#include "tests.h"

void run(const std::string& name, CoinChangeFunc func) {
    for (size_t i = 0; i < tests.size(); ++i) {
        auto start = std::chrono::steady_clock::now();
        func(tests[i].coins, tests[i].amount);
        auto end = std::chrono::steady_clock::now();

        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << name << " | test " << i + 1 << " | " << ms << " ms\n";
    }
}

#define RUN(func) run(#func, func)

int main() {
    // RUN(ваше имя_функции);
    return 0;
}
