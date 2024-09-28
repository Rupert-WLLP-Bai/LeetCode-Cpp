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
     * @brief LC 100. 相同的树
     *
     * @param p
     * @param q
     * @return true
     * @return false
     */
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return compare(p, q);
    }

    bool compare(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;
        if (p == nullptr && q == nullptr) return true;
        if (p->val != q->val) return false;
        return compare(p->left, q->left) && compare(p->right, q->right);
    }
};

int main() {
    return 0;
}