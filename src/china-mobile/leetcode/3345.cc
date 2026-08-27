class Solution {
  public:
    int smallestNumber(int n, int t) {
        // 大于等于n的数，数位乘积能被t整除
        // 1. n % 10 == 0, 直接返回
        // 2. n % 10 != 0,
        // 从n开始，找到第一个数位乘积能被t整除的数，
        // 这个数不会大于 n /10 * 10 + 10
        if (n % 10 == 0) {
            return n;
        }
        int mul_res = 1;
        int res = n;
        while (res <= n / 10 * 10 + 10) {
            if (is_valid(res, t)) {
                return res;
            }
            res += 1;
        }
        return -1;
    }

    bool is_valid(int x, int t) {
        int product = 1;
        while (x > 0) {
            product *= x % 10;
            x /= 10;
        }
        return product % t == 0;
    }
};