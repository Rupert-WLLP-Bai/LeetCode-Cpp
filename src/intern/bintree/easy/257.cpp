#include "../../../../include/bintree.h"
#include <climits>
#include <string>
#include <vector>

class Solution {
  public:
    /**
     * @brief LC 257. 二叉树的所有路径
     *
     * @param root
     * @return vector<string>
     */
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        vector<int> path;
        path.push_back(root->val);
        traversal(root, path, res);
        return res;
    }

  private:
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
        // 终止条件 找到叶子节点
        if (cur->left == nullptr && cur->right == nullptr) {
            // 将路径转换为字符串 添加到结果集中
            string s;
            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1) {
                    s += "->";
                }
            }
            result.push_back(s);
            return;
        }
        // 递归遍历左子树
        if (cur->left != nullptr) {
            path.push_back(cur->left->val);
            traversal(cur->left, path, result);
            path.pop_back();
        }
        // 递归遍历右子树
        if (cur->right != nullptr) {
            path.push_back(cur->right->val);
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, INT_MIN, 5};
    TreeNode *root = buildTree(nums);
    Solution s;
    vector<string> res = s.binaryTreePaths(root);
    for (auto &str : res) {
        cout << str << endl;
    }
    return 0;
}