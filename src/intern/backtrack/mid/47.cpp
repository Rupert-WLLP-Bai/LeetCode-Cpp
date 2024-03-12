#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 47. 全排列 II
     *
     * @param nums
     * @return vector<vector<int>>
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used, path, res);
        return res;
    }

  private:
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &path,
                   vector<vector<int>> &res) {
        // 结束条件
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                // used[i - 1] == false 表示同一树枝nums[i - 1]使用过
                continue;
            }
            used[i] = true; // 标记选择
            path.push_back(nums[i]);
            backtrack(nums, used, path, res);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (auto &v : res) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}