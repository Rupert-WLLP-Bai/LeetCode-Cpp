#include "../../../../include/core.h"
#include <climits>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 152. 乘积最大子数组
     *
     * @param nums
     * @return int
     */
    int maxProduct(vector<int> &nums) {
        // 由于存在负数，故需要维护两个dp数组
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);
        int res = nums[0];
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp_max[i] = max(
                max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), nums[i]);
            dp_min[i] = min(
                min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), nums[i]);
            res = max(res, dp_max[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}