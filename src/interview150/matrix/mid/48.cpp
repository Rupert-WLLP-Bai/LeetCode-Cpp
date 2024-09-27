#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 48. 旋转图像
     *
     * @param matrix
     */
    void rotate(vector<vector<int>> &matrix) {
        // 先转置，再按照中轴线翻转
        int n = matrix.size();
        // 转置
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 按照中轴线翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}