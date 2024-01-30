#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 513. 找树左下角的值
     *
     * @param root
     * @return int
     */
    int findBottomLeftValue(TreeNode *root) {
        int res = root->val;
        int maxDepth = 0;
        stack<pair<TreeNode *, int>> stk; // stack用于存储节点和深度
        stk.push({root, 0});
        while (!stk.empty()) {
            auto [node, depth] = stk.top();
            stk.pop();
            // 如果为叶子节点，且深度大于最大深度，则更新最大深度和结果
            if (node->left == nullptr && node->right == nullptr) {
                if (depth > maxDepth) {
                    maxDepth = depth;
                    res = node->val;
                }
            }
            // 先右后左，这样可以保证最后一个访问到的节点为最左下角的节点
            if (node->right != nullptr) {
                stk.push({node->right, depth + 1});
            }
            if (node->left != nullptr) {
                stk.push({node->left, depth + 1});
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, INT_MIN, 5, 6, INT_MIN, INT_MIN, 7};
    TreeNode *root = buildTree(nums);
    Solution s;
    cout << s.findBottomLeftValue(root) << endl;
    return 0;
}