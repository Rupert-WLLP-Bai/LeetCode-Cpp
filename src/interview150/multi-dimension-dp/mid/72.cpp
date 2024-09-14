#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 72 编辑距离
     *
     * @param word1
     * @param word2
     * @return int
     */
    int minDistance(string word1, string word2) {
        auto n1 = word1.size(), n2 = word2.size();
        // dp[i][j] 表示 word1 的前 i 个字符和 word2 的前 j 个字符的编辑距离
        // 转移方程的建立:
        // 1. 如果 word1[i] == word2[j]，那么 dp[i][j] = dp[i-1][j-1] 不需要操作
        // 2. 如果 word1[i] != word2[j]，那么 dp[i][j] = min(dp[i-1][j-1],
        // dp[i-1][j], dp[i][j-1]) + 1) 分别表示替换、删除、插入
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = i; // word2 为空的情况下 word1 删除所有字符
        }
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = j; // word1 为空的情况下 word2 删除所有字符
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) +
                        1;
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    vector<string> word1 = {"horse", "intention"};
    vector<string> word2 = {"ros", "execution"};
    Solution s;
    for (int i = 0; i < word1.size(); i++) {
        cout << s.minDistance(word1[i], word2[i]) << endl;
    }
    return 0;
}