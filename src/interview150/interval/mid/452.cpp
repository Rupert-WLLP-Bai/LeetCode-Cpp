#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 452. 用最少数量的箭引爆气球
     *
     * @param points
     * @return int
     */
    int findMinArrowShots(vector<vector<int>> &points) {
        // 按照右端点排序
        sort(points.begin(), points.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        // 每次从最小的右端点开始射箭
        int res = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                res++;
                end = points[i][1];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << solution.findMinArrowShots(points) << endl;
    return 0;
}