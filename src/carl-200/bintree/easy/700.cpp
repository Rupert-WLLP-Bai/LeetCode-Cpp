#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 700. 二叉搜索树中的搜索
     *
     * @param root
     * @param val
     * @return TreeNode*
     */
    TreeNode *searchBST(TreeNode *root, int val) {
        auto cur = root;
        while (cur) {
            if (cur->val == val) {
                return cur;
            } else if (cur->val > val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return nullptr;
    }
};

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int val = 2;
    TreeNode *root = buildTree(nums);
    Solution s;
    TreeNode *res = s.searchBST(root, val);
    if (res) {
        cout << res->val << endl;
    } else {
        cout << "null" << endl;
    }
    return 0;
}