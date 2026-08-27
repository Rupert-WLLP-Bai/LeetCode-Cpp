#include <vector>
using namespace std;

class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        // 按照差值排序，选择差值最小的城市
        sort(costs.begin(), costs.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return (a[0] - a[1]) < (b[0] - b[1]);
             });
        int total = 0;
        // 选择前n/2个城市去A城，后n/2个城市去B城
        for (int i = 0; i < costs.size() / 2; i++) {
            total += costs[i][0];
        }
        for (int i = costs.size() / 2; i < costs.size(); i++) {
            total += costs[i][1];
        }
        return total;
    }
};