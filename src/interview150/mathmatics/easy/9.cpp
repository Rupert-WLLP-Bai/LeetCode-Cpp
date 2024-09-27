#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 9. 回文数
     *
     * @param x
     * @return true
     * @return false
     */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = 0, z = x;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y == z;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {121, -121, 10, -101};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " is palindrome: " << sol.isPalindrome(nums[i])
             << endl;
    }
    return 0;
}