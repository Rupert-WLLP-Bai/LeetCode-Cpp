#include <algorithm>
#include <climits>
#include <cstddef>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 1049. 最后一块石头的重量 II
     *
     * @param stones
     * @return int
     */
    int lastStoneWeightII(vector<int> &stones) {
        // 该问题等价于: 将这些石头分成两堆，使得两堆石头的重量差最小
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2; // 目标和
        vector<int> dp(target + 1, 0);
        // dp[i] 表示 石头数量为i时，两堆石头的重量差最小为dp[i]
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                // 装入或不装入背包
                int into_bag = dp[j - stones[i]] + stones[i];
                int out_bag = dp[j];
                dp[j] = max(into_bag, out_bag);
            }
        }
        return sum - 2 * dp[target];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vec_1 = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeightII(vec_1) << endl;
    vector<int> vec_2 = {31, 26, 33, 21, 40};
    cout << s.lastStoneWeightII(vec_2) << endl;
    return 0;
}