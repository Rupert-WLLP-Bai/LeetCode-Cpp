#include "../../../../include/bintree.h"

class Solution {
  public:
    /**
     * @brief LC 106. 从中序与后序遍历序列构造二叉树
     *
     * @param inorder
     * @param postorder
     * @return TreeNode*
     */
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // 后序遍历的最后一个节点为根节点
        // 中序遍历中根节点左边为左子树，右边为右子树
        // 递归构建左右子树
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1);
    }

  private:
    /**
     * @brief 递归构建左右子树
     *
     * @param inorder
     * @param inStart
     * @param inEnd
     * @param postorder
     * @param postStart
     * @param postEnd
     * @return TreeNode*
     */
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd,
                        vector<int> &postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        // 后序遍历的最后一个节点为根节点
        int rootVal = postorder[postEnd];
        // 找到根节点在中序遍历中的位置
        int index = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }
        // 左子树的节点个数
        int leftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        // 递归构建左右子树
        root->left = buildTree(inorder, inStart, index - 1, postorder,
                               postStart, postStart + leftSize - 1);
        root->right = buildTree(inorder, index + 1, inEnd, postorder,
                                postStart + leftSize, postEnd - 1);
        return root;
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution s;
    TreeNode *root = s.buildTree(inorder, postorder);
    printTree(root);
    return 0;
}