#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 202. 快乐数
     *
     * @param n
     * @return true
     * @return false
     */
    bool isHappy(int n) {
        // 思路是用一个set来存储每次计算的平方和
        // 如果平方和重复出现，说明进入了循环，返回false
        unordered_set<int> s;
        while (n != 1) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (s.find(sum) != s.end()) {
                return false;
            }
            s.insert(sum);
            n = sum;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> testcases = {2, 19};
    for (int i = 0; i < testcases.size(); i++) {
        cout << testcases[i] << " is "
             << (s.isHappy(testcases[i]) ? "happy" : "not happy") << endl;
    }
    return 0;
}