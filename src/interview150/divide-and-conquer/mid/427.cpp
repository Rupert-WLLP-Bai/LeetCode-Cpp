#include "../../../../include/core.h"

using namespace std;

class Node {
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
         Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
  public:
    /**
     * @brief LC 427. 建立四叉树
     *
     * @param grid
     * @return Node*
     */
    Node *construct(vector<vector<int>> &grid) {
        return build(grid, 0, 0, grid.size());
    }

  private:
    Node *build(vector<vector<int>> &grid, int x, int y, int len) {
        if (len == 1) {
            // 如果只有一个节点，那么就是叶子节点
            return new Node(grid[x][y], true);
        }
        Node *root = new Node();
        Node *topLeft = build(grid, x, y, len / 2);
        Node *topRight = build(grid, x, y + len / 2, len / 2);
        Node *bottomLeft = build(grid, x + len / 2, y, len / 2);
        Node *bottomRight = build(grid, x + len / 2, y + len / 2, len / 2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
            bottomRight->isLeaf && topLeft->val == topRight->val &&
            topRight->val == bottomLeft->val &&
            bottomLeft->val == bottomRight->val) {
            root->isLeaf = true;
            root->val = topLeft->val;
        } else {
            root->topLeft = topLeft;
            root->topRight = topRight;
            root->bottomLeft = bottomLeft;
            root->bottomRight = bottomRight;
        }
        return root;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0}};
    Node *res = sol.construct(grid);
    return 0;
}