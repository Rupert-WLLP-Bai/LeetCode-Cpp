#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 242 有效的字母异位词
     *
     * @param s
     * @param t
     * @return true
     * @return false
     */
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        // 计数 第一个字符串中的字符
        for (auto c : s) {
            m[c]++;
        }
        // 反向计数 第二个字符串中的字符
        for (auto c : t) {
            m[c]--;
        }
        // 判断是否所有字符的计数都为 0
        for (auto &&i : m) {
            if (i.second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<string> s = {"anagram", "rat"};
    vector<string> t = {"nagaram", "car"};
    Solution solution;
    for (int i = 0; i < s.size(); i++) {
        cout << solution.isAnagram(s[i], t[i]) << endl;
    }
    return 0;
}