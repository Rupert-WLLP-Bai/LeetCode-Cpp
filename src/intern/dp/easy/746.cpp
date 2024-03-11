#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 746. 使用最小花费爬楼梯
     *
     * @param cost
     * @return int
     */
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        for (size_t i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    int ans = sol.minCostClimbingStairs(cost);
    cout << ans << endl;
    return 0;
}