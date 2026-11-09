#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <format>

#include "coins.h"
#include "tests.h"

#include "Mirzabalaev.h"


#include <clocale>
#ifdef _WIN32
    #include <windows.h>
#endif

void run(const std::string& name, CoinChangeFunc func) {
    auto tests = readAllTestCases();

    std::cout << std::format("\nАлгоритм: {}\n", name);

    for (std::size_t i = 0; i < tests.size(); ++i) {
        auto start = std::chrono::steady_clock::now();
        std::map<int, int> result = func(tests[i].coins, tests[i].target_sum);
        auto end = std::chrono::steady_clock::now();

        double ms = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << std::format("\nТест {} | Сумма: {} | Время: {:.3f} мс\n", i + 1, tests[i].target_sum, ms);

        if (result.empty() && tests[i].target_sum > 0) {
            std::cout << "Сумму набрать нельзя\n";
            continue;
        }

        int total = 0;
        std::cout << "Монеты:\n";

        for (const auto& [coin, count] : result) {
            std::cout << std::format("{} руб. x {} ед.\n", coin, count);
            total += count;
        }

        std::cout << std::format("Количество монет: {}\n", total);
    }
}

#define RUN(func) run(#func, func)

int main() {
    #ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    #endif

    // RUN(ваше имя_функции);
    RUN(Mirzabalaev);

    // Если в vs code, то расскомментируйте 
    //std::cout << "Нажмите enter для продолжения...";
    //std::cin.get();

    return 0;
}