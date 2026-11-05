#pragma once
#include <map>
#include <vector>

using CoinChangeFunc = std::map<int, int>(*)(const std::map<int, int>& coins, int target_sum);