#include "../../../../include/core.h"

using namespace std;

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
     * @brief LC 108. 将有序数组转换为二叉搜索树
     *
     * @param nums
     * @return TreeNode*
     */
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        auto root = build(nums, 0, nums.size());
        return root;
    }

  private:
    TreeNode *build(vector<int> &nums, size_t left, size_t right) {
        if (left == right) {
            return nullptr;
        }
        auto mid = (left + right) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid);
        root->right = build(nums, mid + 1, right);
        return root;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sol.sortedArrayToBST(nums);
    printTree(root);
}