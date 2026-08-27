#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        // 10,21,32,43,......,98,210,321,......,987,3210,.....,9876
        int low_bit = 0, l = low, right_bit = 0, r = high;
        while (l / 10 > 0) {
            l /= 10;
            ++low_bit;
        }
        while (r / 10 > 0) {
        }
    }
};