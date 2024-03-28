#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2580. 统计将重叠区间合并成组的方案数
     *
     * @param ranges
     * @return int
     */
    int countWays(vector<vector<int>> &ranges) {
        sort(ranges.begin(), ranges.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[0] < b[0];
             });
        // 合并所有的区间得到m个区间
        auto mergedRanges = merge(ranges);
        int m = mergedRanges.size();
        // 计算2^m 快速幂
        int mod = 1e9 + 7;
        long long res = 1;
        for (int i = 0; i < m; i++) {
            res = res * 2 % mod;
        }
        return int(res);
    }

    vector<vector<int>> merge(vector<vector<int>> &ranges) {
        vector<vector<int>> res;
        for (int i = 0; i < ranges.size(); i++) {
            if (res.empty() || res.back()[1] < ranges[i][0]) {
                res.push_back(ranges[i]);
            } else {
                res.back()[1] = max(res.back()[1], ranges[i][1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> ranges = {{1, 3}, {10, 20}, {2, 5}, {4, 8}};
    Solution s;
    cout << s.countWays(ranges) << endl;
    return 0;
}