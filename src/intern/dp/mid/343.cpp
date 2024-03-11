#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 343. 整数拆分
     *
     * @param n
     * @return int
     */

    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), dp[j] * dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.integerBreak(2) << endl;
    cout << s.integerBreak(10) << endl;
    return 0;
}