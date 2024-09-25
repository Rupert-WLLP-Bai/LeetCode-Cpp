#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 130. 被围绕的区域
     *
     * @param board
     */
    void solve(vector<vector<char>> &board) {
        // BFS
        // 把边界上的'O'都变成'#'
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        markBoundary(board, m, n, q); // 把边界上的'O'都变成'#'
        while (!q.empty()) {
            pair<int, int> cur = q.front(); // 取出队首元素
            q.pop();                        // 弹出队首元素
            for (auto &direction : directions) {
                int x = cur.first + direction[0];
                int y = cur.second + direction[1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                    q.push({x, y});    // 如果是'O'，则入队
                    board[x][y] = '#'; // 标记为已访问
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == '#') ? 'O' : 'X';
            }
        }
    }

  private:
    /**
     * @brief 把边界上的'O'都变成'#'
     *
     * "#" 表示已经访问过
     * @param board
     * @param m
     * @param n
     * @param q
     */
    void markBoundary(vector<vector<char>> &board, int &m, int &n,
                      queue<pair<int, int>> &q) {
        for (int i = 0; i < m; i++) {
            // 左边
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
            // 右边
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                board[i][n - 1] = '#';
            }
        }
        for (int j = 0; j < n; j++) {
            // 上边
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '#';
            }
            // 下边
            if (board[m - 1][j] == 'O') {
                q.push({m - 1, j});
                board[m - 1][j] = '#';
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    solution.solve(board);
    for (auto &row : board) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}