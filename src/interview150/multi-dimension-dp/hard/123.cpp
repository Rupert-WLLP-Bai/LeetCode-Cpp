#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 123. 买卖股票的最佳时机 III
     *
     * @param prices
     * @return int
     */
    int maxProfit(vector<int> &prices) {
        // dp[i][k][0] 表示第 i 天交易了 k 次且不持有股票的最大利润
        // dp[i][k][1] 表示第 i 天交易了 k 次且持有股票的最大利润
        // 转移方程的建立:
        // 1. 如果第 i 天不持有股票，那么可能是第 i-1 天也不持有股票，或者第 i-1
        // 天持有股票，第 i 天卖出
        // 2. 如果第 i 天持有股票，那么可能是第 i-1 天也持有股票，或者第 i-1
        // 天不持有股票，第 i 天买入 初始化条件:
        // 1. dp[0][k][0] = 0
        // 2. dp[0][k][1] = -prices[0]
        // 3. dp[i][0][0] = 0
        // 4. dp[i][0][1] = INT_MIN
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(3, vector<int>(2, 0)));
        for (int i = 0; i < n; i++) {
            for (int k = 2; k >= 1; k--) {
                if (i == 0) {
                    dp[i][k][0] = 0;          // 第 0 天不持有股票
                    dp[i][k][1] = -prices[0]; // 第 0 天持有股票
                    continue;
                }
                if (k == 0) {
                    dp[i][k][0] = 0;       // 不允许交易
                    dp[i][k][1] = INT_MIN; // 不允许交易
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0],
                                  dp[i - 1][k][1] + prices[i]); // 不持有股票
                dp[i][k][1] = max(dp[i - 1][k][1],
                                  dp[i - 1][k - 1][0] - prices[i]); // 持有股票
            }
        }
        return dp[n - 1][2][0]; // 最后一天交易了两次且不持有股票
    }
};

int main() {
    vector<vector<int>> prices = {
        {3, 3, 5, 0, 0, 3, 1, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}, {1}, {}};
    Solution s;
    for (auto &&i : prices) {
        cout << s.maxProfit(i) << endl;
    }
    return 0;
}