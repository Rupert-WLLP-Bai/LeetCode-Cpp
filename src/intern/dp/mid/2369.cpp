#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2369. 检查数组是否存在有效划分
     *
     * @param nums
     * @return true
     * @return false
     */
    bool validPartition(vector<int> &nums) {
        int m = nums.size();
        // dp[i] 表示 nums[0..i] 是否存在有效划分
        vector<bool> dp(m + 1, false);
        // 初始化
        dp[0] = true;
        for (int i = 1; i <= m; i++) {
            if (i >= 2) {
                dp[i] =
                    dp[i] || (dp[i - 2] && twoValid(nums[i - 2], nums[i - 1]));
            }
            if (i >= 3) {
                dp[i] = dp[i] ||
                        (dp[i - 3] &&
                         threeValid(nums[i - 3], nums[i - 2], nums[i - 1]));
            }
        }
        for (int i = 0; i <= m; i++) {
            cout << dp[i] << " ";
        }
        return dp[m];
    }

    bool twoValid(int i, int j) {
        return i == j;
    }

    bool threeValid(int i, int j, int k) {
        return (i == j && j == k) || (i + 1 == j && j + 1 == k);
    }
};

int main() {
    vector<int> nums1 = {4, 4, 4, 5, 6};
    vector<int> nums2 = {
        16021,  16021,  810578, 810578, 74774,  74775,  74776,  74777,  74778,
        74779,  74780,  74781,  74782,  74783,  74784,  74785,  74786,  74787,
        74788,  74789,  74790,  74791,  74792,  74793,  74794,  74795,  74796,
        74797,  74798,  74799,  74800,  74801,  74802,  74803,  74804,  74805,
        74806,  74807,  74808,  74809,  74810,  74811,  74812,  373968, 373969,
        373970, 373971, 373972, 373973, 373974, 373975, 373976, 373977, 373978,
        373979, 373980, 373981, 373982, 274939, 274940, 274941, 274942, 274943,
        274944, 274945, 274946, 274947, 274948, 274949, 274950};
    Solution s;
    cout << boolalpha;
    cout << s.validPartition(nums1) << endl;
    cout << s.validPartition(nums2) << endl;
    return 0;
}
