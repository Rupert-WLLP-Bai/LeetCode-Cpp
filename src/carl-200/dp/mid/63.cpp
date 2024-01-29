#include <cstddef>
#include <iostream>

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
        // 注意边界条件和有障碍的位置的值
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}