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
     * @brief LC 117. 填充每个节点的下一个右侧节点指针 II
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

int main(){
    Solution s;
    Node *root = new Node{1, nullptr, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr, nullptr};
    s.connect(root);
    // 使用next指针遍历
    Node *p = root;
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