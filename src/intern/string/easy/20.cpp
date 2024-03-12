#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 20. 有效的括号
     *
     * @param s
     * @return true
     * @return false
     */
    bool isValid(string s) {
        stack<char> stk;
        for (auto &c : s) {
            switch (c) {
            case '(':
                stk.push(c);
                break;
            case '[':
                stk.push(c);
                break;
            case '{':
                stk.push(c);
                break;
            case ')':
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    stk.push(c);
                break;
            case ']':
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                    stk.push(c);
                break;
            case '}':
                if (!stk.empty() && stk.top() == '{')
                    stk.pop();
                else
                    stk.push(c);
                break;
            default:
                break;
            }
        }
        return stk.empty();
    }
};

int main() {
    string s = "()[]{[()]}";
    Solution sl;
    cout << sl.isValid(s) << endl;
    return 0;
}