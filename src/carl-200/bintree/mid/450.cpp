#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 450. 删除二叉搜索树中的节点
     *
     * @param root
     * @param key
     * @return TreeNode*
     */
    TreeNode *deleteNode(TreeNode *root, int key) {
        // 首先找到要删除的节点
        auto p = root;
        TreeNode *parent = nullptr;
        while (p) {
            if (p->val == key) break;
            parent = p;
            if (p->val > key) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        // 如果没有找到要删除的节点，则直接返回
        if (!p) return root;
        // 如果要删除的节点有两个子节点，则将其右子树的最小节点的值赋给要删除的节点，然后删除右子树的最小节点
        if (p->left && p->right) {
            auto minNode = p->right;
            auto minParent = p;
            while (minNode->left) {
                minParent = minNode;
                minNode = minNode->left;
            }
            p->val = minNode->val;
            p = minNode;
            parent = minParent;
        }
        // 如果要删除的节点是叶子节点或者仅有一个子节点，则直接删除
        auto child = p->left ? p->left : p->right;
        if (!parent) {
            root = child;
        } else if (parent->left == p) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        return root;
    }
};

int main() {
    vector<int> nums = {5, 3, 6, 2, 4, 7};
    int key = 3;
    auto root = buildTree(nums);
    Solution s;
    auto res = s.deleteNode(root, key);
    printTree(res);
    return 0;
}