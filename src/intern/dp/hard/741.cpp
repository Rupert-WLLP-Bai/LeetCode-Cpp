#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 741. 摘樱桃
     *
     * @param grid
     * @return int
     */
    int cherryPickup(vector<vector<int>> &grid) {
        // 首先需要判断是否存在路径
        if (!existPath(grid)) {
            return 0;
        }
        // 从(0,0) 到 (n-1, n-1) 每次只能向右或者向下走
        // 再从(n-1, n-1) 到 (0, 0) 每次只能向左或者向上走
        // 路径经过的1的个数之和最大
        // 可以理解为两个人同时从(0,0)出发，到(n-1,n-1)相遇，再一起返回(0,0)
        // 两个人的路径不能重叠
        // 定义dp数组，dp[i][j][k]表示第一个人在(i,j)，第二个人在(k,l)时的最大路径和
        /*
            定义 dp[r1][c1][r2] 的原因主要有两个方面：

            两个人的路径依赖关系：
            题目要求两个人同时从起点 (0,0) 出发，走到终点
           (n-1,n-1)，并且最终摘到的樱桃最多。我们可以将问题简化为这两个人同时走同一条网格，并且保证他们始终在某个时刻
           t 处于不同的 (r1, c1) 和 (r2, c2) 位置。
            关键是两个人的步数总和是一样的，即 r1 + c1 == r2 +c2。
            也就是说，当两个人走到 (r1, c1) 和 (r2, c2)时，步数是相同的，
            可以用这个条件来约束两个人在网格中的位置。
            因此， c2 可以由 c1 和 r1、r2 确定，
            即 c2 = r1 + c1 -r2。这样我们只需要存储三维的状态
            dp[r1][c1][r2]，就可以唯一确定两个人的位置和他们能够摘到的最大樱桃数。

            减少状态维度：
            通过这种定义，我们避免了在状态转移中引入 c2，从而将四维 DP
            降维到三维。减少一个维度意味着算法的复杂度降低，从而优化了时间和空间效率。
            如果我们直接定义为四维 dp[r1][c1][r2][c2]，状态空间将会是
            O(n^4)，计算量和存储量都会增加。而通过利用步数总和相等的约束关系，三维
            DP 的状态空间是 O(n^3)，显著优化了复杂度。

            总结：
            定义简化：dp[r1][c1][r2] 可以唯一确定两个人的位置
            (r1, c1) 和 (r2, c1 + r1 - r2)，从而避免使用四维数组来表示状态。
            减少复杂度：通过利用 r1 + c1 == r2 + c2的关系，减少了状态的维度，
            使得算法的时间和空间复杂度从 O(n^4) 降低到了 O(n^3)。
         */
        int n = grid.size();
        // 3D DP table to store the maximum cherries two people can pick
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][0] = grid[0][0]; // Start point

        // Iterate over all possible r1, c1, r2
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = 0; r2 < n; r2++) {
                    int c2 =
                        r1 + c1 -
                        r2; // r2 + c2 = r1 + c1, constraint from the problem
                    if (c2 < 0 || c2 >= n || grid[r1][c1] == -1 ||
                        grid[r2][c2] == -1) {
                        continue; // Out of bounds or encountering a thorn (-1)
                    }

                    int currCherries = grid[r1][c1];
                    if (r1 != r2) {
                        currCherries += grid[r2][c2]; // If not same cell, pick
                                                      // cherries from both
                    }

                    // Find the max cherries they could have collected from
                    // their previous step
                    int maxCherries = -1;
                    if (r1 > 0 && r2 > 0)
                        maxCherries = max(maxCherries, dp[r1 - 1][c1][r2 - 1]);
                    if (r1 > 0 && c2 > 0)
                        maxCherries = max(maxCherries, dp[r1 - 1][c1][r2]);
                    if (c1 > 0 && r2 > 0)
                        maxCherries = max(maxCherries, dp[r1][c1 - 1][r2 - 1]);
                    if (c1 > 0 && c2 > 0)
                        maxCherries = max(maxCherries, dp[r1][c1 - 1][r2]);

                    if (maxCherries >= 0) {
                        dp[r1][c1][r2] = maxCherries + currCherries;
                    }
                }
            }
        }

        // The answer is the number of cherries when both people reach (n-1,
        // n-1)
        return max(0, dp[n - 1][n - 1][n - 1]); // If dp[n-1][n-1][n-1] < 0,
                                                // return 0 as no valid path
    }

    bool existPath(vector<vector<int>> &grid) {
        // 从(0,0) 到 (n-1, n-1) 每次只能向右或者向下走
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        // 定义dfs函数，返回从(x,y)到(n-1,n-1)是否存在路径
        function<bool(vector<vector<int>> &, int, int, vector<vector<bool>> &)>
            dfs = [&](vector<vector<int>> &grid, int x, int y,
                      vector<vector<bool>> &visited) -> bool {
            if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                return true;
            }
            visited[x][y] = true;
            if (x + 1 < grid.size() && grid[x + 1][y] != -1 &&
                !visited[x + 1][y]) {
                if (dfs(grid, x + 1, y, visited)) {
                    return true;
                }
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] != -1 &&
                !visited[x][y + 1]) {
                if (dfs(grid, x, y + 1, visited)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(grid, 0, 0, visited);
    }
};

int main() {
    vector<vector<vector<int>>> testcases = {
        {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}},
        {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}}};
    Solution s;
    for (int i = 0; i < testcases.size(); i++) {
        cout << s.cherryPickup(testcases[i]) << endl;
    }
    return 0;
}