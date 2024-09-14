#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 205. 同构字符串
     *
     * @param s
     * @param t
     * @return true
     * @return false
     */
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        // 遍历每一组字符 如果映射关系存在 则判断是否相等
        // 如果映射关系不存在 则添加映射关系
        for (int i = 0; i < s.size(); i++) {
            if (m1.count(s[i]) && m1[s[i]] != t[i]) {
                return false;
            }
            if (m2.count(t[i]) && m2[t[i]] != s[i]) {
                return false;
            }
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    vector<string> s = {"egg", "foo", "paper"};
    vector<string> t = {"add", "bar", "title"};
    Solution solution;
    for (int i = 0; i < s.size(); i++) {
        cout << solution.isIsomorphic(s[i], t[i]) << endl;
    }
    return 0;
}