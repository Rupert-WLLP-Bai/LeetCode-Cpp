#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief LC 416. 分割等和子集
     * 
     * @param nums 
     * @return true 
     * @return false 
     */
    bool canPartition(vector<int>& nums) {
        // 首先nums总和必须是偶数，否则不可能分成两个和相等的子集
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2; // 目标和

        // dp[i][j]表示前i个元素中是否存在和为j的子集
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;    // 前i个元素中存在和为0的子集
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j - nums[i - 1] < 0) {  // 背包容量不足，不能装入第i个物品
                    dp[i][j] = dp[i - 1][j];
                } else {    // 装入或不装入背包
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]]; // 按位或 作用是只要有一个为true，结果就为true
                }
            }
        }

        return dp[nums.size()][target];
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> vec_1 = {1, 5, 11, 5};
    cout << s.canPartition(vec_1) << endl;
    vector<int> vec_2 = {1, 2, 3, 5};
    cout << s.canPartition(vec_2) << endl;
    return 0;
}