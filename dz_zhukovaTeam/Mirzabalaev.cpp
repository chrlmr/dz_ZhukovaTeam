#include "Mirzabalaev.h"
#include <algorithm>
#include <limits>
#include <vector>

std::map<int, int> Mirzabalaev(const std::map<int, int>& coins, int target_sum) {
    if (target_sum < 0) return {};

    const int inf = std::numeric_limits<int>::max();
    
    std::vector<int> dp(target_sum + 1, inf);
    std::vector<int> path(target_sum + 1, -1);

    struct Step {
        int previous;
        int coin;
        int count;
    };

    std::vector<Step> steps = { {-1, 0, 0} };

    dp[0] = 0;
    path[0] = 0;

    for (const auto& [coin, available] : coins) {

        if (coin <= 0 || available <= 0 || coin > target_sum) continue;
        int remaining = std::min(available, target_sum / coin);

        for (long long group = 1; remaining > 0; group *= 2) {
            int count = static_cast<int>(std::min(group, static_cast<long long>(remaining)));

            int value = coin * count;
            remaining -= count;

            for (int sum = target_sum; sum >= value; --sum) {
                if (dp[sum - value] == inf || dp[sum - value] + count >= dp[sum]) continue;
                dp[sum] = dp[sum - value] + count;
                steps.push_back({ path[sum - value], coin, count });
                path[sum] = static_cast<int>(steps.size()) - 1;
            }
        }
    }

    if (dp[target_sum] == inf) return {};

    std::map<int, int> result;

    for (int i = path[target_sum]; i > 0; i = steps[i].previous) {
        result[steps[i].coin] += steps[i].count;
    }
    return result;
}
