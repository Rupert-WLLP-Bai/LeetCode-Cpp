#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 376. 摆动序列
     *
     * @param nums
     * @return int
     */
    int wiggleMaxLength(vector<int> &nums) {
        // 找出所有的峰值和谷值 组成最后的序列
        // 可能会存在
        // 1 - 2 - 2 - 2 - 1  需要找出峰值2
        // 1 - 2 - 2 - 2 - 3  需要找出首尾两个值
        if (nums.size() <= 1) {
            return nums.size();
        }
        int cur = 0; // 当前差值
        int pre = 0; // 前一组的差值
        int res = 1; // 初始化为1 默认最右侧存在一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            cur = nums[i + 1] - nums[i]; // 计算当前差值
            // 只在摆动方向发生变化的时候更新pre的值
            if ((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0)) {
                res++;
                pre = cur;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    Solution s1;
    cout << s1.wiggleMaxLength(nums) << endl;
    return 0;
}