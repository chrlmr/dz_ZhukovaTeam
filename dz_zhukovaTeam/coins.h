#pragma once
#include <vector>

constexpr int NO_SOLUTION = -1;

using CoinChangeFunc = int (*)(const std::vector<int>& coins, int amount);
