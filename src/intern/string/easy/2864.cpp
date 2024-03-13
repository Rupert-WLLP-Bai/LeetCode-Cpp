#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2864. 最大二进制奇数
     *
     * @param s
     * @return string
     */
    string maximumOddBinaryNumber(string s) {
        // 遍历s 分别获得1和0的数量
        // 如果1只有一位 则返回000...01
        // 否则返回11...00..01

        // 使用stable_partition 把1放在前面
        stable_partition(s.begin(), s.end(), [](char c) { return c == '1'; });

        // 找到最后一个1
        auto last_one = s.find_last_of('1');

        // 如果没有1 或者只有一个1
        if (last_one == string::npos || last_one == 0) {
            swap(s[0], s[s.size() - 1]);
            return s;
        }

        // 把最后一个1放到字符串的最后
        swap(s[last_one], s[s.size() - 1]);

        // 返回结果
        return s;
    }
};

int main() {
    vector<string> ss = {"010", "0101"};
    Solution solution;
    for (auto s : ss) {
        cout << "s: " << s << " res: " << solution.maximumOddBinaryNumber(s)
             << endl;
    }
    return 0;
}