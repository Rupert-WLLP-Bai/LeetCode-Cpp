#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 515. 在每个树行中找最大值
     *
     * @param root 根节点
     * @return vector<int> 每一层的最大值
     */
    vector<int> largestValues(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        vector<int> result;
        for (auto &r : res) {
            auto m = max_element(r.begin(), r.end());
            result.emplace_back(*m);
        }
        return result;
    }

  private:
    void dfs(TreeNode *root, int depth, vector<vector<int>> &level) {
        if (root == nullptr) {
            return;
        }
        if (depth == level.size()) {
            // 当前层的第一个元素
            level.push_back(vector<int>());
        }
        level[depth].push_back(root->val);
        dfs(root->left, depth + 1, level);
        dfs(root->right, depth + 1, level);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 5, 3, INT_MIN, 9};
    TreeNode *root = buildTree(nums);
    Solution sol;
    vector<int> ans = sol.largestValues(root);
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}