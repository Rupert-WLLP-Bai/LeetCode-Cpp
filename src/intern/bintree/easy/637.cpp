#include <climits>
#include <iostream>
#include <vector>
#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 637. 二叉树的层平均值
     *
     * @param root 根节点
     * @return vector<double> 每一层的平均值
     */
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        vector<vector<int>> level;
        dfs(root, 0, level);
        for (auto &l : level) {
            double sum = 0;
            for (auto &i : l) {
                sum += i;
            }
            res.push_back(sum / l.size());
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
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nums);
    Solution sol;
    vector<double> ans = sol.averageOfLevels(root);
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}