#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 538. 把二叉搜索树转换为累加树
     *
     * @param root
     * @return TreeNode*
     */
    TreeNode *convertBST(TreeNode *root) {
        // 右 根 左 遍历
        stack<TreeNode *> stk;
        TreeNode *p = root;
        int sum = 0;
        while (p || !stk.empty()) {
            while (p) {
                // 先遍历右子树
                stk.push(p);
                p = p->right;
            }
            // 右子树遍历完毕
            // 访问栈顶元素
            p = stk.top();
            stk.pop();
            sum += p->val; // 累加
            p->val = sum;  // 当前节点val值更新
            p = p->left;   // 转向左子树
        }
        return root;
    }
};

int main() {
    vector<int> nums = {4, 1,       6,       0,       2,
                        5, 7,       INT_MIN, INT_MIN, INT_MIN,
                        3, INT_MIN, INT_MIN, INT_MIN, 8};
    auto root = buildTree(nums);
    auto res = Solution().convertBST(root);
    printTree(res);
    return 0;
}