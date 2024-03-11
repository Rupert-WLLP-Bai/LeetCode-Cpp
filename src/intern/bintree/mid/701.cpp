#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 701. 二叉搜索树中的插入操作
     *
     * @param root
     * @param val
     * @return TreeNode*
     */
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        auto node = new TreeNode(val);
        if (!root) return node;
        auto p = root;
        while (p) {
            // 如果当前节点的值大于val，则插入的位置在左子树
            if (p->val > val) {
                if (!p->left) {
                    p->left = node;
                    break;
                }
                // 如果当前节点的左子树不为空，则继续向左子树遍历
                p = p->left;
            } else {
                if (!p->right) {
                    p->right = node;
                    break;
                }
                p = p->right;
            }
        }
        return root;
    }
};

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int val = 5;
    auto root = buildTree(nums);
    Solution s;
    auto res = s.insertIntoBST(root, val);
    printTree(res);
    return 0;
}