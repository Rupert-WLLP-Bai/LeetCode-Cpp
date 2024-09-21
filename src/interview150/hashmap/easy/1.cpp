#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 1. 两数之和
     *
     * @param nums
     * @param target
     * @return vector<int>
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            // 从nums[0]开始遍历
            // 如果target - nums[i]在map中，返回map[target - nums[i]]和i
            if (m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], i}; // C++11 的语法 列表初始化语法
            }
            m[nums[i]] = i;
        }
        // 否则返回空
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}