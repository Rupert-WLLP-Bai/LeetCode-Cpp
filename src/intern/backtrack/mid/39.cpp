#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 39. 组合总和
     *
     * @param candidates
     * @param target
     * @return vector<vector<int>>
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, path, res);
        return res;
    }

  private:
    void dfs(vector<int> &candidates, int target, int begin, vector<int> &path,
             vector<vector<int>> &res) {
        if (target < 0) {
            // 超出范围
            return;
        }
        if (target == 0) {
            // 满足要求
            res.push_back(path);
            return;
        }
        // for 循环回溯
        for (int i = begin; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution solution;
    auto res = solution.combinationSum(candidates, target);
    for (auto r : res) {
        cout << "res: ";
        for (auto i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}