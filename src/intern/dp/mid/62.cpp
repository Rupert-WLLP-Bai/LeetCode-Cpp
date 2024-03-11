#include <cstddef>
#include <iostream>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 62. 不同路径
     *
     * @param m
     * @param n
     * @return int
     */
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (size_t i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (size_t i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 2) << endl;
    cout << s.uniquePaths(7, 3) << endl;
    cout << s.uniquePaths(3, 3) << endl;
    return 0;
}