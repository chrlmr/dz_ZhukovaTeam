#pragma once

#include <map>
#include <string>
#include <fstream>

struct TestCase {
    int target_sum;
    std::map<int, int> coins;
};

TestCase readTestCase(const std::string& filepath) {
    // Формат файла:
    // В первой строчке целевая сумма
    // В следующих строчках "количество номинал"
    // Пример: 
    // 15
    // 4 3  (3 монеты по 4 рубля)
    // 10 2 (2 монеты по 10 рублей)
    // 12 1 (1 монета по 12 рублей)
    
    int target_sum;
    std::map<int, int> coins; // Ключ: номинал, Значение: количество

    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << '\n';
        return {};
    }

    if (!(file >> target_sum)) {
        std::cerr << "Ошибка чтения target_sum!" << '\n';
        return {};
    }

    int coin_count; 
    int coin_value;

    while (file >> coin_value >> coin_count) {
        coins[coin_value] = coin_count; 
    }

    return { target_sum, coins };
}


inline std::vector<TestCase> tests = {
    // Ваши тестовые данные,
};
