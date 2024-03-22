#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 322. 零钱兑换
     *
     * @param coins
     * @param amount
     * @return int
     */
    int coinChange(vector<int> &coins, int amount) {
        // dp[i] 表示凑成金额 i 所需的最少硬币数量
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // 遍历所有金额
        for (int i = 1; i <= amount; i++) {
            // 遍历所有硬币
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;
    return 0;
}