#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 98. 验证二叉搜索树
     *
     * @param root
     * @return true
     * @return false
     */
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, nullptr, nullptr);
    }

  private:
    bool isValidBST(TreeNode *root, TreeNode *left, TreeNode *right) {
        if (root == nullptr) return true;
        if (left != nullptr && root->val <= left->val) return false;
        if (right != nullptr && root->val >= right->val) return false;
        return isValidBST(root->left, left, root) &&
               isValidBST(root->right, root, right);
    }
};

int main() {
    vector<int> nums = {5, 1, 4, INT_MIN, INT_MIN, 3, 6};
    TreeNode *root = buildTree(nums);
    Solution s;
    cout << s.isValidBST(root) << endl;
    return 0;
}