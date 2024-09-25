#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 399. 除法求值
     *
     * @param equations
     * @param values
     * @param queries
     * @return vector<double>
     */
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        // 1. 建图
        unordered_map<string, unordered_map<string, double>>
            graph; // 邻接表 graph[u][v] = w 表示 u -> v 的权重为 w
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            graph[u][v] = w;       // u -> v 的权重为 w
            graph[v][u] = 1.0 / w; // v -> u 的权重为 1 / w
        }

        // 2. 查询
        vector<double> res;
        for (auto &query : queries) {
            string u = query[0];
            string v = query[1];
            if (!graph.count(u) || !graph.count(v)) {
                res.push_back(-1.0);
                continue;
            }
            if (u == v) {
                res.push_back(1.0);
                continue;
            }
            unordered_set<string> visited;
            // DFS 搜索 u -> v 的路径 并返回权重
            double ans = dfs(graph, u, v, visited);
            res.push_back(ans);
        }
        return res;
    }

  private:
    /**
     * @brief DFS 搜索 u -> v 的路径 并返回权重
     *
     * @param graph
     * @param u
     * @param v
     * @param visited
     * @return double
     */
    double dfs(unordered_map<string, unordered_map<string, double>> &graph,
               const string &u, const string &v,
               unordered_set<string> &visited) {
        if (u == v) {
            return 1.0;
        }
        visited.insert(u);
        for (auto &[neighbor, weight] : graph[u]) {
            if (visited.count(neighbor)) {
                continue;
            }
            double ans = dfs(graph, neighbor, v, visited);
            if (ans != -1.0) {
                return ans * weight;
            }
        }
        return -1.0;
    }
};

int main() {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {
        {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    Solution solution;
    vector<double> res = solution.calcEquation(equations, values, queries);
    for (auto &r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}