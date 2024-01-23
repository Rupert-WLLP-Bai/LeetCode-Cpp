#include "bintree.h"

TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    
    int index = 0;
    TreeNode* root = new TreeNode(nums[index++]);
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty() && index < nums.size()) {
        TreeNode* node = q.front();
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