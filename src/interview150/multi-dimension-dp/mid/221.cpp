#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        auto m = matrix.size();                       // row
        auto n = matrix[0].size();                    // col
        vector<vector<int>> dp(m, vector<int>(n, 0)); // initialize dp
        // tips: dp[i][j] means the side length of the maximum square whose
        // bottom-right corner is the cell with index (i, j) in the original
        // martix
        int maxSide = 0;
        // initialize the first row
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0'; // convert char to int
            maxSide = max(maxSide, dp[i][0]);
        }
        // initialize the first col
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0'; // convert char to int
            maxSide = max(maxSide, dp[0][j]);
        }
        // transition
        // if the current cell value is 1, then the side length of the square
        // ending at this cell will be the minimum of the top, left, and
        // top-left cells plus 1
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) +
                        1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};

int main() {
    vector<vector<vector<char>>> matrix = {{{'1', '0', '1', '0', '0'},
                                            {'1', '0', '1', '1', '1'},
                                            {'1', '1', '1', '1', '1'},
                                            {'1', '0', '0', '1', '0'}},
                                           {{'0', '1'}, {'1', '0'}},
                                           {{'0'}}};
    Solution s;
    for (auto &&i : matrix) {
        cout << s.maximalSquare(i) << endl;
    }
    return 0;
}