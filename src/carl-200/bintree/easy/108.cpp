#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 108. 将有序数组转换为二叉搜索树
     *
     * @param nums
     * @return TreeNode*
     */
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }

  private:
    TreeNode *constructBST(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        // 找到中间位置 保证左右子树的节点数量差不超过 1
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]); // 以中间位置的元素作为根节点
        root->left = constructBST(nums, left, mid - 1); // 递归构造左子树
        root->right = constructBST(nums, mid + 1, right); // 递归构造右子树
        return root;
    }
};

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    auto root = s.sortedArrayToBST(nums);
    printTree(root);
    return 0;
}
