#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 222. 完全二叉树的节点个数
     *
     * @param root
     * @return int
     */
    int countNodes(TreeNode *root) {
        auto l = root, r = root;
        int hl = 0, hr = 0;
        while (l) {
            l = l->left;
            hl++;
        }
        while (r) {
            r = r->right;
            hr++;
        }
        // 如果左右子树高度相同，则是一棵满二叉树, 节点数为 2^h - 1
        if (hl == hr) {
            return pow(2, hl) - 1;
        }
        // 如果左右高度不同，则按照普通二叉树的逻辑计算
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    TreeNode *root = buildTree(nums);
    Solution s;
    int res = s.countNodes(root);
    cout << res << endl;
    return 0;
}