#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 207. 课程表
     *
     * @param numCourses
     * @param prerequisites
     * @return bool
     */
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>()); // 邻接表
        vector<int> indegree(numCourses, 0);                  // 入度数组
        for (auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]); // 有向边 pre[1] -> pre[0]
            indegree[pre[0]]++;              // pre[0] 的入度加 1
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i); // 把入度为 0 的节点放入队列
            }
        }
        // BFS 将入度为 0 的节点放入队列，然后遍历队列
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            numCourses--; // 修正剩余课程数
            for (auto &next : graph[cur]) {
                indegree[next]--; // 当前节点的邻居的入度减 1
                if (indegree[next] == 0) {
                    q.push(next); // 如果入度为 0，则放入队列
                }
            }
        }
        return numCourses == 0; // 如果所有节点都入队出队过，则返回 true
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    Solution solution;
    cout << solution.canFinish(numCourses, prerequisites) << endl;
    return 0;
}