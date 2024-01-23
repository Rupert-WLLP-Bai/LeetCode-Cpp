#include <iostream>
#include <vector>
#include "../../../include/bintree.h"

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 102. 二叉树的层序遍历
     *
     * @param root 根节点
     * @return vector<vector<int>> 层序遍历结果
     */
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }

  private:
    void dfs(TreeNode *root, int depth, vector<vector<int>> &res) {
        if (root == nullptr) {
            return; // 递归终止条件
        }
        if (depth == res.size()) {
            res.push_back(
                vector<int>()); // 当前层的第一个节点，创建一个新的空层
        }
        res[depth].push_back(root->val);  // 将当前节点加入到对应层
        dfs(root->left, depth + 1, res);  // 递归左子树
        dfs(root->right, depth + 1, res); // 递归右子树
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nums);
    Solution s;
    vector<vector<int>> res = s.levelOrder(root);
    for (auto &v : res) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
