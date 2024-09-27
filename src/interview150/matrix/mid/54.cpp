#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 54. 螺旋矩阵
     *
     * @param matrix
     * @return vector<int>
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // 从左到右，从上到下，从右到左，从下到上
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        }
        // 定义边界
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        // 循环
        int total = matrix.size() * matrix[0].size();
        while (res.size() < total) {
            // 从左到右
            for (int i = left; i <= right && res.size() < total; i++) {
                res.push_back(matrix[top][i]);
            }
            // 从上到下
            for (int i = top + 1; i <= bottom - 1 && res.size() < total; i++) {
                res.push_back(matrix[i][right]);
            }
            // 从右到左
            for (int i = right; i >= left && res.size() < total; i--) {
                res.push_back(matrix[bottom][i]);
            }
            // 从下到上
            for (int i = bottom - 1; i >= top + 1 && res.size() < total; i--) {
                res.push_back(matrix[i][left]);
            }
            // 更新边界
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = sol.spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}