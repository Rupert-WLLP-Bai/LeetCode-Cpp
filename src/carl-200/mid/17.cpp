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
        if (digits.empty()) {
            return {};
        }
        backtrack(0, digits);
        return result;
    }

  private:
    vector<string> result; // 最终结果
    string path;           // 中间结果
    const unordered_multimap<char, string> m = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void backtrack(int index, const string &digits) {
        // index 表示遍历到第几个数字
        // 结束条件
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        // 用index取对应的字符集
        char digit = digits[index];
        auto iter = m.find(digit); // 找到对应的字符集
        string str = iter->second; // 取出字符集
        // 遍历字符集
        for (int i = 0; i < str.size(); i++) {
            path.push_back(str[i]);
            backtrack(index + 1, digits);
            path.pop_back();
        }

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