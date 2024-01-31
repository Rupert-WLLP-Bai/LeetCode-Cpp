#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 235. 二叉搜索树的最近公共祖先
     *
     * @param root
     * @param p
     * @param q
     * @return TreeNode*
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) {
            return root;
        }
        // 如果 p 和 q 都在 root 的右子树中，则返回右子树的最近公共祖先
        // p, q 的值都大于 root 的值时，说明 p, q 都在 root 的右子树中
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // 如果 p 和 q 都在 root 的左子树中，则返回左子树的最近公共祖先
        // p, q 的值都小于 root 的值时，说明 p, q 都在 root 的左子树中
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // 如果 p 和 q 一个在 root 的左子树中，一个在 root 的右子树中
        // 则返回 root
        return root;
    }
};

int main() {
    vector<int> nums = {6, 2, 8, 0, 4, 7, 9, INT_MAX, INT_MAX, 3, 5};
    auto root = buildTree(nums);
    auto p = findNode(root, 2);
    auto q = findNode(root, 8);
    Solution s;
    auto res = s.lowestCommonAncestor(root, p, q);
    cout << res->val << endl;
    return 0;
}