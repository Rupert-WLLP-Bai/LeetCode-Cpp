#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 111. 二叉树的最小深度
     *
     * @param root
     * @return int
     */
    int minDepth(TreeNode *root) {
        // 层序找到第一个叶子节点
        if (root == nullptr) {
            return 0;
        }
        // 层序遍历
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            // 遍历当前层
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                // 判断是否为叶子节点
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                // 将当前节点的左右子节点加入队列
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nums);
    Solution s;
    int res = s.minDepth(root);
    cout << res << endl;
    return 0;
}