#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 200. 岛屿数量
     *
     * @param grid
     * @return int
     */
    int numIslands(vector<vector<char>> &grid) {
        // use queue to store the position of '1'
        // BFS
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (auto &direction : directions) {
                            int x = cur.first + direction[0];
                            int y = cur.second + direction[1];
                            if (x >= 0 && x < m && y >= 0 && y < n &&
                                grid[x][y] == '1') {
                                q.push({x, y});
                                grid[x][y] = '0';
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << solution.numIslands(grid) << endl;
    return 0;
}