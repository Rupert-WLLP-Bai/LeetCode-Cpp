#include <climits>
#include <iostream>
#include <vector>
#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 199. 二叉树的右视图
     *
     * @param root 根节点
     * @return vector<int> 右视图
     */
    vector<int> rightSideView(TreeNode *root) {
        // 右视图相当于层序遍历每一层的最右边
        vector<int> res;
        vector<vector<int>> level;
        dfs(root, 0, level);
        for (auto &l : level) {
            res.push_back(l.back()); // 放入最后一个节点
        }
        return res;
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
    vector<int> nums = {1, 2, 3, INT_MIN, 5, INT_MIN, 4};
    TreeNode *root = buildTree(nums);
    Solution sol;
    vector<int> ans = sol.rightSideView(root);
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}