#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

// 测试用例
TreeNode *createTree() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// 前序遍历
void preOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 前序遍历 - 非递归
void preOrderNonRecursive(TreeNode *root) {
    stack<TreeNode *> s;
    s.push(root);
    while (!s.top()) {
        auto node = s.top();
        // 对顶部操作 这里是cout
        cout << node->val << " ";
        // pop
        s.pop();
        // 先右后左
        if (node->right) {
            s.push(node->right);
        }
        if (node->left) {
            s.push(node->left);
        }
    }
}

// 中序遍历
void inOrder(TreeNode *root) {
}

int main() {
    return 0;
}