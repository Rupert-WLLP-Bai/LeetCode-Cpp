#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief LC 216. 组合总和 III
     *
     * @param k
     * @param n
     * @return vector<vector<int>> 找出所有相加之和为 n 的 k 个数的组合
     */
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result; // 最终结果
    vector<int> path;           // 符合条件的结果

    void backtrack(int n, int k, int start) {
        // 提前结束条件：若path中元素个数已经达到k，则不再进行递归
        if (path.size() == k) {
            int sum = accumulate(path.begin(), path.end(), 0); // 计算路径和
            if (sum == n) {
                result.push_back(path); // 如果和为n，添加到结果中
            }
            return; // 直接返回，无需再继续执行后面的代码
        }
        
        // 横向遍历的上界是9
        for (int i = start; i <= 9; ++i) {
            path.push_back(i); // 选取当前数字
            backtrack(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销选择
        }
    }
};


int main() {
    int k = 9, n = 45;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum3(k, n);
    for (auto &v : ans) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}