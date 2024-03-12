#include "../../../../include/core.h"

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 22. 括号生成
     *
     * @param n
     * @return vector<string>
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrack(n, n, path, res);
        return res;
    }

  private:
    void backtrack(int left, int right, string &path, vector<string> &res) {
        // 左右括号都用完了，说明找到了一个合法的括号组合
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        // 如果左括号还有剩余，添加左括号
        if (left > 0) {
            path.push_back('('); // 选择
            backtrack(left - 1, right, path, res);
            path.pop_back(); // 回溯
        }
        // 如果右括号剩余多于左括号，添加右括号
        if (right > left) {
            path.push_back(')'); // 选择
            backtrack(left, right - 1, path, res);
            path.pop_back(); // 回溯
        }
    };
};

int main() {
    Solution s;
    auto res = s.generateParenthesis(3);
    for (auto &str : res) {
        cout << str << endl;
    }
    return 0;
}