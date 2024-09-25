#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 219. 存在重复元素 II
     *
     * @param nums
     * @param k
     * @return true
     * @return false
     */
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        // 思路是用一个map来存储每个元素的下标
        // 如果元素重复出现，且下标差小于等于k，返回true
        unordered_map<int, int> m; // key: 值, value: 下标
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
                // 依次遍历数组，如果当前元素已经在map中，且下标差小于等于k
                return true;
            }
            // 将当前的元素和下标存入map
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> testcases = {
        {1, 2, 3, 1}, {1, 0, 1, 1}, {1, 2, 3, 1, 2, 3}};
    vector<int> ks = {3, 1, 2};
    Solution s;
    for (int i = 0; i < testcases.size(); i++) {
        cout << (s.containsNearbyDuplicate(testcases[i], ks[i]) ? "true"
                                                                : "false")
             << endl;
    }
    return 0;
}