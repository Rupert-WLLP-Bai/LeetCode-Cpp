#include "../../../../include/core.h"

class Solution {
  public:
    /**
     * @brief LC 209. 长度最小的子数组
     *
     * @param target
     * @param nums
     * @return int
     */
    int minSubArrayLen(int target, vector<int> &nums) {
        // 滑动窗口
        int n = nums.size();
        int left = 0, right = 0; // 左右指针
        int sum = 0;             // 窗口内的和
        int res = INT_MAX;       // 结果
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right - left + 1); // 窗口长度
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main() {
    vector<vector<int>> inputs = {
        {2, 3, 1, 2, 4, 3},
        {1, 4, 4},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 3, 4, 5},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12}};
    vector<int> targets = {7, 4, 11, 11, 11, 213};
    for (int i = 0; i < inputs.size(); i++) {
        cout << Solution().minSubArrayLen(targets[i], inputs[i]) << endl;
    }
}