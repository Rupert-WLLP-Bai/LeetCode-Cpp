#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 617. 合并二叉树
     *
     * @param root1
     * @param root2
     * @return TreeNode*
     */
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        auto node = new TreeNode(root1->val + root2->val);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};

int main() {
    vector<int> nums1 = {1, 3, 2, 5};
    vector<int> nums2 = {2, 1, 3, INT_MIN, 4, INT_MIN, 7};
    TreeNode *root1 = buildTree(nums1);
    TreeNode *root2 = buildTree(nums2);
    Solution s;
    TreeNode *res = s.mergeTrees(root1, root2);
    printTree(res);
    return 0;
}