#include "../../../../include/core.h"

class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {
    }

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution {
  public:
    /**
     * @brief LC 117. 填充每个节点的下一个右侧节点指针 II
     *
     * @param root
     * @return Node*
     */
    Node *connect(Node *root) {
        // 层序遍历
        if (!root) {
            return nullptr;
        }
        queue<Node *> q;
        q.push(root);
        vector<Node *> layer;
        vector<vector<Node *>> res;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                layer.push_back(node);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(layer);
            layer.clear();
        }
        for (auto &layer : res) {
            for (int i = 0; i < layer.size() - 1; i++) {
                layer[i]->next = layer[i + 1];
            }
        }
        return root;
    }
};

int main() {
    return 0;
}