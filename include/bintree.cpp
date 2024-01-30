#include "bintree.h"

TreeNode *buildTree(const vector<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }

    int index = 0;
    auto root = new TreeNode(nums[index++]);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty() && index < nums.size()) {
        TreeNode *node = q.front();
        q.pop();

        if (nums[index] != INT_MIN) {
            node->left = new TreeNode(nums[index]);
            q.push(node->left);
        }
        index++;

        if (index < nums.size() && nums[index] != INT_MIN) {
            node->right = new TreeNode(nums[index]);
            q.push(node->right);
        }
        index++;
    }

    return root;
}

void printTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    int levelSize = 1;

    while (!q.empty()) {
        int nullCount =
            0; // Count the number of null nodes in the current level

        for (int i = 0; i < levelSize; i++) {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr) {
                nullCount++;
                continue;
            }

            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }

        if (nullCount == levelSize) { // If all nodes in the current level are
                                      // null, break the loop
            break;
        }

        cout << endl;
        levelSize = q.size();
    }
}