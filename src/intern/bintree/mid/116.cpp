#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution {
  public:
    /**
     * @brief LC 116. 填充每个节点的下一个右侧节点指针
     *
     * @param root 根节点
     * @return Node* 节点
     */
    Node *connect(Node *root) {
        vector<vector<Node *>> level;
        dfs(root, 0, level);
        // 遍历每一层 依次连接
        for (const auto &nodes : level) {
            for (size_t i = 0; i < nodes.size() - 1; i++) {
                nodes[i]->next = nodes[i + 1];
            }
            nodes.back()->next = nullptr;
        }
        return root;
    }

  private:
    void dfs(Node *root, int depth, vector<vector<Node *>> &level) {
        if (root == nullptr) {
            return;
        }
        if (depth == level.size()) {
            // 当前层的第一个元素
            level.push_back(vector<Node *>());
        }
        level[depth].push_back(root);
        dfs(root->left, depth + 1, level);
        dfs(root->right, depth + 1, level);
    }
};

Node* constructTree(vector<int> nums) {
    if (nums.empty()) return nullptr;

    vector<Node*> nodes(nums.size(), nullptr);
    
    // Initialize all nodes.
    for (size_t i = 0; i < nums.size(); ++i) {
        nodes[i] = new Node{nums[i], nullptr, nullptr, nullptr};
    }

    // Link the child nodes.
    for (size_t i = 0; i < nums.size(); ++i) {
        if (2 * i + 1 < nums.size()) nodes[i]->left = nodes[2 * i + 1]; // Left child
        if (2 * i + 2 < nums.size()) nodes[i]->right = nodes[2 * i + 2]; // Right child
    }

    return nodes[0]; // The root node
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Node *root = constructTree(nums);
    Solution s;
    Node *res = s.connect(root);
    // 使用next指针层序遍历
    Node *p = res;
    while (p != nullptr) {
        Node *q = p;
        while (q != nullptr) {
            cout << q->val << " ";
            q = q->next;
        }
        cout << endl;
        p = p->left;
    }
    return 0;
}