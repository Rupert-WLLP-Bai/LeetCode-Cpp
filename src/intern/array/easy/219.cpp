#include "../../../../include/core.h"
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
        // 使用哈希表存储元素的下标
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 判断是否存在重复元素
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
                return true;
            }
            // 更新元素的下标
            map[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsNearbyDuplicate(nums, 3) << endl;
    return 0;
}