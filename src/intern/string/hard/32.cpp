#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<int> stk; // 存放左括号的下标
        int res = 0;
        stk.push(-1); // 用于计算长度
        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            // 如果是左括号，入栈
            if (s[i] == '(') {
                stk.push(i); // 存放左括号的下标
            } else {
                // 如果是右括号，出栈
                stk.pop();
                // 如果栈为空，说明当前右括号没有匹配的左括号，入栈
                if (stk.empty()) {
                    stk.push(i); // 存放右括号的下标
                } else {
                    // 计算长度
                    // 当前右括号的下标减去栈顶元素的下标
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = ")()())";
    cout << solution.longestValidParentheses(s) << endl;
    return 0;
}