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
     * @brief LC 101. 对称二叉树
     *
     * @param root
     * @return true
     * @return false
     */
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return judge(root->left, root->right);
    }

  private:
    bool judge(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 && t2) return false;
        if (t1 && !t2) return false;
        if (t1->val != t2->val) return false;
        return judge(t1->left, t2->right) && judge(t1->right, t2->left);
    }
};

int main() {
    return 0;
}