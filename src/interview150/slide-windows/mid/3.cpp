#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 3 无重复字符的最长子串
     *
     * @param s
     * @return int
     */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;  // 用于存储窗口中的字符
        int left = 0, right = 0; // 左右指针
        int res = 0;             // 记录最大长度
        while (right < s.size()) {
            if (us.find(s.at(right)) != us.end()) {
                us.erase(s.at(left++)); // 右侧字符已经在窗口中，左侧指针右移
            } else {
                us.insert(
                    s.at(right++)); // 右侧字符不在窗口中，右侧指针右移 添加字符
                res = max(res, right - left);
            }
        }
        return res;
    }
};

int main() {
    vector<string> testSet = {"abcabcbb", "bbbbb", "pwwkew", "",        " ",
                              "au",       "aab",   "dvdf",   "tmmzuxt", "abba"};

    Solution s;
    for (string test : testSet) {
        cout << s.lengthOfLongestSubstring(test) << endl;
    }
    return 0;
}