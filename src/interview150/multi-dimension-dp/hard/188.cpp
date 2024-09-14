#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 188. 买卖股票的最佳时机 IV
     *
     * @param k
     * @param prices
     * @return int
     */
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        if (k >= n / 2) {
            int dp_i_0 = 0, dp_i_1 = -prices[0];
            for (int i = 1; i < n; i++) {
                int tmp = dp_i_0;
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, tmp - prices[i]);
            }
            return dp_i_0;
        }
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] =
                    max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
};

int main() {
    vector<int> k = {2, 2, 2, 2};
    vector<vector<int>> prices = {{2, 4, 1},
                                  {3, 2, 6, 5, 0, 3},
                                  {3, 3, 5, 0, 0, 3, 1, 4},
                                  {1, 2, 4, 2, 5, 7, 2, 4, 9, 0}};
    Solution s;
    for (int i = 0; i < k.size(); i++) {
        cout << s.maxProfit(k[i], prices[i]) << endl;
    }
    return 1;
}