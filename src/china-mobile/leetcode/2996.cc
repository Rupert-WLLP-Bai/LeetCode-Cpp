#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int missingInteger(vector<int> &nums) {
        int n = nums.size();
        // track existing numbers
        unordered_set<int> s(nums.begin(), nums.end());
        int total = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }
        int res = total - 1;
        while (s.count(++res));
        return res;
    }
};