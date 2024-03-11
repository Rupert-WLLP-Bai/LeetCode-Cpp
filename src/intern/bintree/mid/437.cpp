#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    /**
     * @brief LC 429. N 叉树的层序遍历
     *
     * @param root 根节点
     * @return vector<vector<int>> 层序遍历结果
     */
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> level;
        dfs(root, 0, level);
        return level;
    }

  private:
    void dfs(Node *root, int depth, vector<vector<int>> &res) {
        if (root == nullptr) {
            return;
        }
        if (depth == res.size()) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        // 递归遍历下一层
        for (auto &c : root->children) {
            dfs(c, depth + 1, res);
        }
    }
};



int main() {
    cout<< "Need to implement the function to build a N-ary tree." << '\n';
    return 0;
}