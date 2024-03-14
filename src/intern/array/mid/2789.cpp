#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2789. 合并后数组中的最大元素
     *
     * @param nums
     * @return long long
     */
    long long maxArrayValue(vector<int> &nums) {
        long long lastValue = nums.back();
        // 从后向前合并
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= lastValue) {
                lastValue += nums[i];
            } else {
                lastValue = nums[i];
            }
        }
        return lastValue;
    }
};

int main() {
    vector<int> nums = {2, 3, 7, 9, 3};
    Solution solution;
    cout << solution.maxArrayValue(nums) << endl;
    return 0;
}