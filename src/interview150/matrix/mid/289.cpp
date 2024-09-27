#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 289. 生命游戏
     *
     * @param board
     */
    void gameOfLife(vector<vector<int>> &board) {
        // 思路: 使用额外的状态来表示下一轮的状态
        int m = board.size();
        int n = board[0].size();
        // 定义 8 个方向
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        // 遍历矩阵
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 统计周围的活细胞数量
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        (board[x][y] == 1 || board[x][y] == 2)) {
                        live++; // 活细胞
                    }
                }
                // 更新状态
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    // board[i][j] = 2 表示当前是活细胞，下一轮死亡
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    // board[i][j] = 3 表示当前是死细胞，下一轮复活
                    board[i][j] = 3;
                }
            }
        }
        // 更新状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] %= 2; // 为2的值变为0，为3的值变为1 符合题目要求
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    sol.gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}