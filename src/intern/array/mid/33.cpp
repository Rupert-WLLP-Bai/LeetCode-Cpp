#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 33. 搜索旋转排序数组
     *
     * @param nums
     * @param target
     * @return int
     */
    int search(vector<int> &nums, int target) {
        // 如果数组长度为1
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        // 二分查找
        // 分割之后会得到一个有序数组和一个无序数组
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 如果左边有序
            if (nums[0] <= nums[mid]) {
                // 如果target在左边
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 如果target在右边
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3};
    int target = 0;
    cout << solution.search(nums, target) << endl;
    return 0;
}