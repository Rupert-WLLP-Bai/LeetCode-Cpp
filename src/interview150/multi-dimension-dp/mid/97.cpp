#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 97. 交错字符串
     *
     * @param s1
     * @param s2
     * @param s3
     * @return true
     * @return false
     */
    bool isInterleave(string s1, string s2, string s3) {
        auto n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        // 首先判断长度是否匹配
        if (n1 + n2 != n3) {
            return false;
        }
        // dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符是否可以交错组成 s3
        // 的前 i+j 个字符 转移方程的建立:
        // 1. 如果 s1[i] == s3[i+j]，那么 dp[i][j] = dp[i-1][j]
        // 2. 如果 s2[j] == s3[i+j]，那么 dp[i][j] = dp[i][j-1]
        // 3. 如果 s1[i] == s3[i+j] && s2[j] == s3[i+j]，那么 dp[i][j] =
        // dp[i-1][j] || dp[i][j-1]
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n1; i++) {
            // 首先初始化边界条件
            // dp[i][0] 表示 s1 的前 i 个字符和 s2 的前 0 个字符是否可以交错组成
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= n2; i++) {
            // dp[0][i] 表示 s1 的前 0 个字符和 s2 的前 i
            // 个字符是否可以交错组成s
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}