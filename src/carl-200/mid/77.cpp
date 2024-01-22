#include <iostream>
#include <vector>

using namespace std;

// 回溯法模板
// void backtracking(参数) {
//     if (终止条件) {
//         存放结果;
//         return;
//     }

//     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//         处理节点;
//         backtracking(路径，选择列表); // 递归
//         回溯，撤销处理结果
//     }
// }

class Solution {
  public:
    /**
     * @brief LC 77. 组合
     *
     * @param n
     * @param k
     * @return vector<vector<int>> [1, n] 中所有可能的 k 个数的组合
     */
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }

  private:
    vector<vector<int>> result; // 最终结果
    vector<int> path;           // 符合条件的结果

    void backtrack(int n, int k, int startIndex) {
        // 终止条件是path填满
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = startIndex; i <= n; i++) {
            // 纵向遍历
            path.push_back(i);
            backtrack(n, k, i + 1); // 递归
            path.pop_back();
        }
    }
};

int main() {
    int n = 4, k = 2;
    Solution sol;
    vector<vector<int>> ans = sol.combine(n, k);
    for (auto &v : ans) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
