#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 63. 不同路径 II
     *
     * @param obstacleGrid
     * @return int
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // dp[i][j] 表示到达 (i, j) 的路径数
        // 转移方程的建立:
        // 1. 如果 obstacleGrid[i][j] == 1，那么 dp[i][j] = 0
        // 即障碍本身所在的位置不可达
        // 2. 如果 obstacleGrid[i][j] == 0，那么 dp[i][j] = dp[i-1][j] +
        // dp[i][j-1]
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化第 0 行和第 0 列
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }
        // 转移方程 从索引 1 的位置开始遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 如果 obstacleGrid[i][j] == 1，那么 dp[i][j] = 0
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<vector<int>>> obstacleGrid = {
        {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, {{0, 1}, {0, 0}}, {{0}}};
    Solution s;
    for (auto &&i : obstacleGrid) {
        cout << s.uniquePathsWithObstacles(i) << endl;
    }
    return 0;
}