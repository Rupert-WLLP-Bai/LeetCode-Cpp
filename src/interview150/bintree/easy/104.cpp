#include "../../../../include/core.h"
#include "bintree.h"

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
     * @brief LC 104. 二叉树的最大深度
     *
     * @param root
     * @return int
     */
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = depth(root->left, 1);
        int right = depth(root->right, 1);
        return max(left, right);
    }

  private:
    int depth(TreeNode *t, int d) {
        if (t == nullptr) {
            return d;
        }
        return max(depth(t->left, d + 1), depth(t->right, d + 1));
    }
};

int main() {
    Solution s;
}