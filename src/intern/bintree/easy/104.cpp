#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 104. 二叉树的最大深度
     *
     * @param root
     * @return int
     */
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 5, 3, INT_MIN, 9};
    TreeNode *root = buildTree(nums);
    Solution sol;
    int ans = sol.maxDepth(root);
    cout << ans << endl;
    return 0;
}