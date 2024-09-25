#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 76. 最小覆盖子串
     *
     * @param s
     * @param t
     * @return string
     */
    string minWindow(string s, string t) {
        int left = 0;         // 左指针
        int right = 0;        // 右指针
        int start = 0;        // 最小覆盖子串的起始位置
        int minLen = INT_MAX; // 最小覆盖子串的长度
        int count = 0; // 记录窗口中已经包含了多少个t中的字符
        unordered_map<char, int> window; // 记录窗口中各个字符出现的次数
        unordered_map<char, int> needs; // 记录t中各个字符出现的次数
        for (char c : t) {
            needs[c]++;
        }
        // 向右扩展
        while (right < s.size()) {
            char c = s[right];
            if (needs.count(c)) {
                window[c]++;
                if (window[c] == needs[c]) {
                    count++;
                }
            }
            right++;

            // 判断左侧窗口是否要收缩
            while (count == needs.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char d = s[left];
                if (needs.count(d)) {
                    if (window[d] == needs[d]) {
                        count--;
                    }
                    window[d]--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout << s.minWindow(s1, s2) << endl;
    return 0;
}