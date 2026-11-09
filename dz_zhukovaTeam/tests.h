#pragma once

#include <map>
#include <string>
#include <fstream>

struct TestCase {
    int target_sum;
    std::map<int, int> coins;
};

std::vector<std::string> testPaths = {
    // Ваши пути к тестовым данным
    "test/Mirzabalaev_average.txt",
    "test/Mirzabalaev_best.txt",
    "test/Mirzabalaev_worst.txt",
};


TestCase readTestCase(const std::string& filepath) {
    // Считывает тестовый пример из одного файла
    // Формат файла:
    // В первой строчке целевая сумма
    // В следующих строчках "номинал количество"
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

std::vector<TestCase> readAllTestCases() {
    // Читает все тесты из testPaths и возвращать вектор из TestCase
    std::vector<TestCase> result {};
    result.reserve(testPaths.size());
    
    for (const auto& path : testPaths) {
        result.push_back(readTestCase(path));
    }

    return result;
}


