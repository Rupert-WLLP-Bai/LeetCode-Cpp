#include <algorithm>
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
        vector<vector<int>> res;
        if (intervals.empty()) {
            return res;
        }
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        // 排序之后的区间一定是左端点有序的 在合并区间时只需要考虑右端点
        res.push_back(intervals[0]); // 先把第一个区间放进去
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {
                // 如果当前区间的左端点小于等于res中最后一个区间的右端点
                // 说明有重叠 更新res中最后一个区间的右端点为两者的最大值
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                // 没有重叠
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = solution.merge(intervals);
    for (vector<int> &v : result) {
        cout << "[" << v[0] << ", " << v[1] << "]" << endl;
    }
    return 0;
}