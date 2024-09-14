#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 49. 字母异位词分组
     *
     * @param strs
     * @return vector<vector<string>>
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>>
            m; // key: sorted string, value: original string
        for (auto &&s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end()); // sort the string
            m[tmp].push_back(s);          // group the anagrams
        }
        vector<vector<string>> res;
        for (auto &&i : m) {
            res.push_back(i.second);
        }
        return res;
    }
};

int main() {
    vector<vector<string>> strs = {{"eat", "tea", "tan", "ate", "nat", "bat"}};
    Solution s;
    for (auto &&i : strs) {
        auto res = s.groupAnagrams(i);
        for (auto &&j : res) {
            for (auto &&k : j) {
                cout << k << " ";
            }
            cout << endl;
        }
    }
    return 0;
}