#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {
    }
};

TreeNode *buildTree(const vector<int> &nums);
void printTree(TreeNode *root);
void _preorder(TreeNode *root, vector<int> &nums);
void _inorder(TreeNode *root, vector<int> &nums);
void _postorder(TreeNode *root, vector<int> &nums);
TreeNode *findNode(TreeNode *root, int val);