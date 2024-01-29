#include <iostream>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 509. 斐波那契数
     *
     * @param n
     * @return int
     */
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution sol;
    int ans = sol.fib(10);
    cout << ans << endl;
    return 0;
}