#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 654. 最大二叉树
     *
     * @param nums
     * @return TreeNode*
     */
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return buildTree(nums);
    }

  private:
    tuple<vector<int>, int, vector<int>> search(vector<int> &nums) {
        int max = INT_MIN;
        int maxIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIdx = i;
            }
        }
        vector<int> left = vector<int>(nums.begin(), nums.begin() + maxIdx);
        vector<int> right = vector<int>(nums.begin() + maxIdx + 1, nums.end());
        return make_tuple(left, max, right);
    }

    TreeNode *buildTree(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        auto [left, max, right] = search(nums);
        TreeNode *root = new TreeNode(max);
        root->left = buildTree(left);
        root->right = buildTree(right);
        return root;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution s;
    TreeNode *root = s.constructMaximumBinaryTree(nums);
    printTree(root);
    return 0;
}