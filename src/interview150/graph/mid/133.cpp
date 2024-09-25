#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    /**
     * @brief LC 133. 克隆图
     *
     * @param node
     * @return Node*
     */
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<Node *, Node *> visited; // 原图节点 -> 新图节点
        queue<Node *> q;                       // BFS 队列
        q.push(node);                          // 放入第一个节点
        visited[node] = new Node(node->val); // 放入队列的同时，创建新节点
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            for (auto &neighbor : cur->neighbors) {
                // 如果没有访问过，则创建新节点并放入队列
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // 如果访问过，则直接放入新图节点的邻居中
                visited[cur]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};

int main() {
    return 0;
}