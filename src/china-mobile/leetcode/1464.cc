#include <vector>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // 扫描两次找出最大的两个数
        int max1 = 0, max2 = 0;
        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};