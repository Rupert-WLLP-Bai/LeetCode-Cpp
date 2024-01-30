#include "../../../../include/bintree.h"

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
        return compare(root->left, root->right);
    }

  private:
    bool compare(TreeNode *left, TreeNode *right) {
        // left == nullptr and right == nullptr
        if (left == nullptr && right == nullptr) {
            return true;
        }
        // left == nullptr and right != nullptr
        // left != nullptr and right == nullptr
        if (left != nullptr && right == nullptr) {
            return false;
        }
        if (left == nullptr && right != nullptr) {
            return false;
        }
        // left != nullptr and right != nullptr
        if (left->val != right->val) {
            return false;
        }
        return compare(left->left, right->right) &&
               compare(left->right, right->left);
    }
};

int main() {
    vector<int> nums = {2, 3, 3, 4, 5, INT_MIN, 4};
    TreeNode *root = buildTree(nums);
    Solution s;
    bool res = s.isSymmetric(root);
    cout << res << endl;
    return 0;
}
