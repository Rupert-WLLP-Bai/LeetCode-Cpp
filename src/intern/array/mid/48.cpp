#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 48. 旋转图像
     *
     * @param matrix
     */
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 先沿着对角线翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再沿着中轴线翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution s;
    s.rotate(matrix);
    for (auto &v : matrix) {
        for (auto &i : v) {
            cout << setw(2) << i << " ";
        }
        cout << endl;
    }
    return 0;
}