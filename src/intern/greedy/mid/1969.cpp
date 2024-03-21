#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 1969. 数组元素的最小非零乘积
     *
     * @param p
     * @return int
     */
    int minNonZeroProduct(int p) {
        // 每一位上1的个数为: 2^(p-1)
        // 每一位上0的个数为: 2^(p-1) - 1
        // 必然会多出一个 11..11 相当于 2^p - 1
        // 剩下的01均分，相当于和一定的一组数，需要其乘积最小
        // 故将其分为11...10 和 00...01 乘积为: 2^p - 2
        // 组数为: 2^(p-1) - 1
        // 故最小乘积为: (2^(p-1)-1)*(2^p-2)*(2^p-1) % (10^9+7)
        long long mod = 1e9 + 7;
        long long a = (1ll << p) % mod;
        long long b = (a - 1) % mod;
        long long c = (a - 2) % mod;
        long long res = (b * qmi(c, (1ll << (p - 1)) - 1, mod)) % mod;
        return res;
    }

    long long qmi(long long a, long long b, long long mod) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    int p = 3;
    Solution s;
    cout << s.minNonZeroProduct(p) << endl;
    return 0;
}