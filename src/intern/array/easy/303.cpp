#include "../../../../include/core.h"
using namespace std;

/**
 * @brief LC 303. 区域和检索 - 数组不可变
 *
 */
class NumArray {
  public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }

  private:
    vector<int> sums;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;
    return 0;
}