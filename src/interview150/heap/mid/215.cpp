#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 215. 数组中的第K个最大元素
     *
     * @param nums
     * @param k
     * @return int
     */
    int findKthLargest(vector<int> &nums, int k) {
        // o(n)
        // 1 <= k <= nums.size() <= 10^5
        // -10^4 <= nums[i] <= 10^4
        // 桶排序
        vector<int> bucket(20001, 0);
        for (int num : nums) {
            bucket[num + 10000]++;
        }
        int count = 0;
        for (int i = 20000; i >= 0; i--) {
            count += bucket[i];
            if (count >= k) {
                return i - 10000;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}