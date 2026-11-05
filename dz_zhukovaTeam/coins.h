#pragma once
#include <map>
#include <vector>

using CoinChangeFunc = std::map<int, int>(*)(const std::vector<int>& coins, int amount);