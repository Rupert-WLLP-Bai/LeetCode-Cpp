#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include "../../../../include/bintree.h"

class Solution {
  public:
    int minDepth(TreeNode *root) {
        // 层序 找到第一个叶子节点
        if (root == nullptr) {
            return 0;
        }
        int depth = 1;
        vector<TreeNode *> q;
        q.push_back(root);
        while (!q.empty()) {
            vector<TreeNode *> tmp;
            for (auto node : q) {
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                if (node->left != nullptr) {
                    tmp.push_back(node->left);
                }
                if (node->right != nullptr) {
                    tmp.push_back(node->right);
                }
            }
            q = tmp;
            depth++;
        }
        return depth;
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nums);
    Solution sol;
    int ans = sol.minDepth(root);
    cout << ans << endl;
    return 0;
}