#include <iostream>
#include <vector>
#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 226. 翻转二叉树
     *
     * @param root
     * @return TreeNode*
     */
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main() {
    vector<int> nums = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *root = buildTree(nums);
    Solution s;
    TreeNode *res = s.invertTree(root);
    printTree(res);
    return 0;
}