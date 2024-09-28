#include "../../../../include/core.h"
#include "bintree.h"
#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

int main() {
    return 0;
}