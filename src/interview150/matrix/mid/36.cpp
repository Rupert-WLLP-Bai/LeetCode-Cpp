#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 36. 有效的数独
     *
     * @param board
     * @return true
     * @return false
     */
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, int> rows[9];  // 每行的数字出现次数
        unordered_map<int, int> cols[9];  // 每列的数字出现次数
        unordered_map<int, int> boxes[9]; // 每个宫格的数字出现次数
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int n = num - '0';
                    int box_index = (i / 3) * 3 + j / 3;
                    rows[i][n]++;
                    cols[j][n]++;
                    boxes[box_index][n]++;
                    if (rows[i][n] > 1 || cols[j][n] > 1 ||
                        boxes[box_index][n] > 1) {
                        return false; // 判断是否出现重复数字
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << sol.isValidSudoku(board) << endl;
    return 0;
}