#include "../../../../include/bintree.h"
#include <climits>

class Solution {
  public:
    /**
     * @brief LC 110. 平衡二叉树
     *
     * @param root
     * @return true
     * @return false
     */
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        // 当前节点满足平衡二叉树的条件，且左右子树也满足平衡二叉树的条件
        return abs(height(root->left) - height(root->right)) <= 1 &&
               isBalanced(root->left) && isBalanced(root->right);
    }

  private:
    /**
     * @brief 返回二叉树的高度
     *
     * @param root
     * @return int
     */
    int height(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nums);
    Solution s;
    bool res = s.isBalanced(root);
    cout << res << endl;
    return 0;
}
