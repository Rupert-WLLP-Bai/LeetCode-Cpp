#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN; // 最大的三个
        int s1 = INT_MAX, s2 = INT_MAX;               // 最小的两个
        for (int x : nums) {
            if (x > m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x > m2) {
                m3 = m2;
                m2 = x;
            } else if (x > m3) {
                m3 = x;
            }

            if (x < s1) {
                s2 = s1;
                s1 = x;
            } else if (x < s2) {
                s2 = x;
            }
        }
        return max(m1 * m2 * m3, s1 * s2 * m1);
    }
};