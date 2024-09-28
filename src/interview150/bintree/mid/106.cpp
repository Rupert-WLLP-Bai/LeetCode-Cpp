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
     * @brief LC 106. 从中序与后序遍历序列构造二叉树
     *
     * @param inorder
     * @param postorder
     * @return TreeNode*
     */
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
    }

  private:
    TreeNode *build(vector<int> &inorder, int inStart, int inEnd,
                    vector<int> &postorder, int postStart, int postEnd) {
        // 中序: | ------ l ------ | root | ------ r ------ |
        // 后序: | ------ l ------ | ------ r ------ | root |
        if (postStart > postEnd) {
            return nullptr;
        }
        int rootVal = postorder[postEnd];
        int index = inStart;
        while (inorder[index] != rootVal) {
            index++;
        }
        int leftSize = index - inStart;
        auto root = new TreeNode(rootVal);
        root->left = build(inorder, inStart, index - 1, postorder, postStart,
                           postStart + leftSize - 1);
        root->right = build(inorder, index + 1, inEnd, postorder,
                            postStart + leftSize, postEnd - 1);
        return root;
    }
};

int main() {
    return 0;
}