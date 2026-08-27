#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        // 滑动窗口内 所有数出现的次数小于等于k 找出这个最长的窗口
        unordered_map<int, int> m;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            ++m[nums[right]];
            // 当 nums[right] 出现次数超过 k 时，从左端收缩直到恢复合法
            while (m[nums[right]] > k) {
                --m[nums[left++]];
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// 2026.08.12