#include "../../../../include/core.h"
#include "bintree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    /**
     * @brief LC 105. 从前序与中序遍历序列构造二叉树
     *
     * @param preorder
     * @param inorder
     * @return TreeNode*
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 前序决定上下 中序决定左右
        // 前序: | root | ------ l ------ | ------ r ------ |
        // 中序: | ------ l ------ | root | ------ r ------ |
        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1);
    }

  private:
    /**
     * @brief 构建二叉树
     *
     * @param preorder 前序遍历的数组
     * @param preStart 前序遍历的起始位置
     * @param preEnd
     * @param inorder
     * @param inStart
     * @param inEnd
     * @return TreeNode*
     */
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }
        int rootVal = preorder[preStart];
        int index = inStart;
        while (inorder[index] != rootVal) {
            index++;
        }
        int leftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder,
                           inStart, index - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder,
                            index + 1, inEnd);
        return root;
    }
};

int main() {
    return 0;
}