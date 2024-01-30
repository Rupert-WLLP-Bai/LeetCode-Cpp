#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 112. 路径总和
     *
     * @param root
     * @param targetSum
     * @return true
     * @return false
     */
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (targetSum == root->val && root->left == nullptr &&
            root->right == nullptr) {
            return true;
        }
        // 递归判断左右
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    vector<int> nums = {5, 4, 8,       11,      INT_MIN, 13, 4,
                        7, 2, INT_MIN, INT_MIN, INT_MIN, 1};
    TreeNode *root = buildTree(nums);
    Solution s;
    cout << s.hasPathSum(root, 22) << endl;
    return 0;
}