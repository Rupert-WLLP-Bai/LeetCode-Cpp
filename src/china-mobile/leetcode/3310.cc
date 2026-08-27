#include <vector>
#include <numeric>
using namespace std;

class Solution {
  public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>> &invocations) {
        vector<vector<int>> g(n);
        for (auto &e : invocations) g[e[0]].push_back(e[1]);

        vector<int> visited(n, 0);
        function<void(int)> dfs = [&](int u) {
            visited[u] = 1;
            for (int v : g[u])
                if (!visited[v]) dfs(v);
        };
        dfs(k);

        for (auto &e : invocations)
            if (!visited[e[0]] && visited[e[1]]) {
                vector<int> all(n);
                // 初始化 all 为 0 到 n-1
                iota(all.begin(), all.end(), 0);
                return all;
            }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!visited[i]) ans.push_back(i);
        return ans;
    }
};