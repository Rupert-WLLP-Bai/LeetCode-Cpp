#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 114. 二叉树展开为链表
     *
     * @param root
     */
    void flatten(TreeNode *root) {
        // 1. 将左子树插入到右子树的地方
        // 2. 将原来的右子树接到左子树的最右边节点
        // 3. 考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null

        // 循环找到第一个左子树
        auto p = root;

        while (p) {
            if (p->left) {
                // 找到左子树的最右节点
                auto q = p->left;
                while (q->right) {
                    q = q->right;
                }
                // 将原来的右子树接到左子树的最右边节点
                q->right = p->right;
                // 将左子树插入到右子树的地方
                p->right = p->left;
                p->left = nullptr;
            }
            p = p->right;
        }
    }

    void flatten_recursive(TreeNode *root) {
        if (!root) {
            return;
        }
        flatten_recursive(root->left);
        flatten_recursive(root->right);
        auto left = root->left;
        auto right = root->right;
        root->left = nullptr;
        root->right = left;
        while (root->right) {
            root = root->right;
        }
        root->right = right;
    }
};

int main() {
    vector<int> nums = {1, 2, 5, 3, 4, INT_MIN, 6};
    auto root = buildTree(nums);
    printTree(root);
    Solution solution;
    solution.flatten(root);
    cout << "After flatten:" << endl;
    printTree(root);
    return 0;
}