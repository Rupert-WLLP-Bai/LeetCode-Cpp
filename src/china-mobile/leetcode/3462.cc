#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
  public:
    long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k) {
        // 第一步：把每行排序后，取前 limits[i] 个元素（即该行可贡献的最大候选）
        // 第二步：把所有行的候选汇总，取最大的 k 个
        // 第三步：求和返回
        priority_queue<int, vector<int>, greater<>>
            pq; // 小顶堆，维护当前最大的 k 个候选
        long long ans = 0;
        for (int i = 0; i < (int)grid.size(); ++i) {
            // 行内从大到小排序，取前 min(limits[i], 行大小) 个
            auto &row = grid[i];
            sort(row.begin(), row.end(), greater<int>());
            int cnt = min((int)row.size(), limits[i]);
            for (int j = 0; j < cnt; ++j) {
                if ((int)pq.size() < k) {
                    pq.push(row[j]);
                    ans += row[j];
                } else if (!pq.empty() && row[j] > pq.top()) {
                    ans -= pq.top();
                    pq.pop();
                    pq.push(row[j]);
                    ans += row[j];
                }
                // 否则 row[j] 比堆顶小，舍弃
            }
        }
        return ans;
    }
};