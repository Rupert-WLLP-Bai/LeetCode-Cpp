#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 78. 子集
     *
     * @param nums
     * @return vector<vector<int>>
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        // [&] 表示按引用传递, [=] 表示按值传递
        function<void(int)> backtrack = [&](int start) {
            res.push_back(path);
            for (int i = start; i < n; i++) {
                path.push_back(nums[i]);
                backtrack(i + 1); // 回溯下一种情况
                path.pop_back();
            }
        };
        backtrack(0);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> res = solution.subsets(nums);
    for (auto &v : res) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}