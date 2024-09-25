#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 57. 插入区间
     *
     * @param intervals
     * @param newInterval
     * @return vector<vector<int>>
     */
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval) {
        vector<vector<int>> result;
        vector<int> tmp = newInterval;
        bool inserted = false; // 标记是否已经插入了tmp

        for (int i = 0; i < intervals.size(); i++) {
            // 插入的值在右侧
            if (intervals[i][1] < tmp[0]) {
                result.push_back(intervals[i]);
            }
            // 插入的区间在左侧
            else if (intervals[i][0] > tmp[1]) {
                if (!inserted) {
                    result.push_back(tmp); // 一旦发现区间在右侧，插入 tmp
                    inserted = true;
                }
                result.push_back(intervals[i]); // 后续直接插入所有区间
            }
            // 区间有重叠
            else {
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
            }
        }

        // 如果 tmp 没有被插入，则插入它
        if (!inserted) {
            result.push_back(tmp);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = solution.insert(intervals, newInterval);
    for (vector<int> v : result) {
        cout << "[" << v[0] << ", " << v[1] << "]" << endl;
    }
    return 0;
}