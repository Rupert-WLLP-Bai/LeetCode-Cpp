#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 228. 汇总区间
     *
     * @param nums
     * @return vector<string>
     */
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) {
            return result;
        }
        int start = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (nums[i - 1] == start) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" +
                                     to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }
        // 处理最后一个区间
        if (nums[n - 1] == start) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = solution.summaryRanges(nums);
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}