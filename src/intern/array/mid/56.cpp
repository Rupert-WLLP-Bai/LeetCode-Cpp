#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 56. 合并区间
     *
     * @param intervals
     * @return vector<vector<int>>
     */
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // 按照左端点排序
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        for (auto &interval : intervals) {
            // 由于已经按照左端点排序，所以只需要比较res的最后一个区间的右端点
            if (res.empty() || res.back()[1] < interval[0]) {
                // 使用back()获取最后一个元素
                // 如果res为空或者res的最后一个区间的右端点小于当前区间的左端点
                // 表示当前区间与res的最后一个区间没有交集
                res.push_back(interval);
            } else {
                // 否则表示有交集，更新res的最后一个区间的右端点
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    vector<vector<int>> res = s.merge(intervals);
    for (auto &v : res) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}