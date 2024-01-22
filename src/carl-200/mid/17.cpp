#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 17. 电话号码的字母组合
     *
     * @param digits 数字字符串
     * @return vector<string> 所有可能的字母组合
     */
    vector<string> letterCombinations(string digits) {
        // 字符和字符串相对应
        const unordered_multimap<char, string> m({{'2', "abc"},
                                                  {'3', "def"},
                                                  {'4', "ghi"},
                                                  {'5', "jkl"},
                                                  {'6', "mno"},
                                                  {'7', "pqrs"},
                                                  {'8', "tuv"},
                                                  {'9', "wxyz"}});

        
    }

  private:
    vector<vector<int>> result; // 最终结果
    vector<int> path;           // 符合条件的结果

    void backtrack() {
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for (const auto &str : res) {
        cout << str << endl;
    }
    return 0;
}