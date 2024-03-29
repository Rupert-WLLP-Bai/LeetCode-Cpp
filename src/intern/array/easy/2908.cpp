#include "core.h"
#include <climits>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2908 元素和最小的山形三元组 1
     *
     * @param nums
     * @return int
     */
    int minimumSum(vector<int> &nums) {
        int minSum = INT_MAX;
        bool flag = false;
        int m = nums.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    if (nums[i] < nums[j] && nums[j] > nums[k]) {
                        minSum = min(minSum, nums[i] + nums[j] + nums[k]);
                        flag = true;
                    }
                }
            }
        }
        return flag ? minSum : -1;
    }
};

int main() {
    vector<int> nums = {8, 6, 1, 5, 3};
    Solution solution;
    cout << solution.minimumSum(nums) << endl;
    return 0;
}