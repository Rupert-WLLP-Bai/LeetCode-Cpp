#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 73. 矩阵置零
     *
     * @param matrix
     */
    void setZeroes(vector<vector<int>> &matrix) {
        // 使用第一行和第一列来标记 0
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0 = false, col0 = false;
        // 判断第一行和第一列是否有 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                row0 = true;
                break;
            }
        }
        // 遍历矩阵，使用第一行和第一列来标记 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 根据第一行和第一列的标记来更新矩阵
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 更新第一行和第一列
        if (row0) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    sol.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}