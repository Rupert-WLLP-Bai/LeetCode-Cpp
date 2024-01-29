#include <iostream>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 70. 爬楼梯
     *
     * @param n
     * @return int
     */
    int climbStairs(int n) {
        int dp[n + 1];
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int ans = sol.climbStairs(10);
    cout << ans << endl;
    return 0;
}
