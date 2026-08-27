#include <vector>
using namespace std;

class Solution {
  public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        // 维护一个长度为k的滑动窗口，窗口内元素的和为sum
        int left = 0, right = 0, sum = 0, count = 0;
        while (right < arr.size()) {
            sum += arr[right];
            if (right - left + 1 == k) {
                if (sum / k >= threshold) {
                    count++;
                }
                sum -= arr[left];
                left++; // 左指针右移
            }
            right++; // 右指针右移
        }
        return count;
    }
};