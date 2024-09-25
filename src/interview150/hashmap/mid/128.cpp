#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 128. 最长连续序列
     *
     * @param nums
     * @return int
     */
    int longestConsecutive(vector<int> &nums) {
        // 每次找当前元素的左右
        // 如果左右有元素，就将当前元素的左右删除
        // 直到左右没有元素
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            if (s.find(num) == s.end()) {
                continue;
            }
            s.erase(num);
            int pre = num - 1, next = num + 1;
            while (s.find(pre) != s.end()) {
                s.erase(pre--);
            }
            while (s.find(next) != s.end()) {
                s.erase(next++);
            }
            res = max(res, next - pre - 1);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> testcases = {{100, 4, 200, 1, 3, 2},
                                     {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}};
    Solution s;
    for (int i = 0; i < testcases.size(); i++) {
        cout << s.longestConsecutive(testcases[i]) << endl;
    }
    return 0;
}