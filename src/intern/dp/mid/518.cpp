#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 518. 零钱兑换 II
     *
     * @param amount
     * @param coins
     * @return int
     */
    int change(int amount, vector<int> &coins) {
        // dp[i] 表示金额为 i 时的组合数
        // 状态转移方程：dp[i] = dp[i] + dp[i - coin]
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    Solution s;
    cout << "amount: " << amount << " coins: ";
    for (auto c : coins) {
        cout << c << " ";
    }
    cout << " result: " << s.change(amount, coins) << endl;
    return 0;
}