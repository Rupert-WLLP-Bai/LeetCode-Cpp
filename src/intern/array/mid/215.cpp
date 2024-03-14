#include "../../../../include/core.h"
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
        // 计数排序
        vector<int> count(20001, 0);
        for (int num : nums) {
            count[num + 10000]++;
        }
        int ans = 0;
        for (int i = count.size() - 1; i >= 0; i--) {
            if (count[i] > 0) {
                k -= count[i];
                if (k <= 0) {
                    ans = i - 10000;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}