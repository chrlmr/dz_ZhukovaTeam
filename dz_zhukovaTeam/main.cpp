#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include "coins.h"
#include "tests.h"

void run(const std::string& name, CoinChangeFunc func) {
    for (size_t i = 0; i < tests.size(); ++i) {
        auto start = std::chrono::steady_clock::now();
        std::map<int, int> result = func(tests[i].coins, tests[i].target_sum);
        auto end = std::chrono::steady_clock::now();

        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << name << " тест " << i + 1 << " | " << ms << " ms | ";

        if (result.empty() && tests[i].target_sum > 0) {
            std::cout << "сумму набрать нельзя\n";
            continue;
        }
        int total = 0;
        for (const auto& [coin, count] : result) {
            std::cout << coin << ":" << count << " ";
            total += count;
        }
        std::cout << "(итого " << total << ")\n";
    }
}

#define RUN(func) run(#func, func)

int main() {
    // RUN(ваше имя_функции);
    return 0;
}