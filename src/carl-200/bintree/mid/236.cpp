#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 236. 二叉树的最近公共祖先
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
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if (l && r) {
            return root;
        }
        if (!l && r) {
            return r;
        }
        if (l && !r) {
            return l;
        }
        return nullptr;
    }
};

int main() {
    vector<int> nums = {3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4};
    TreeNode *root = buildTree(nums);
    TreeNode *p = findNode(root, 5);
    TreeNode *q = findNode(root, 4);
    Solution s;
    auto res = s.lowestCommonAncestor(root, p, q);
    cout << res->val << endl;
    return 0;
}