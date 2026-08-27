class Solution {
  public:
    int maxProduct(int n) {
        // 分解每一位, 维护两个数字, 一个是最大值, 一个是次大值
        int max1 = 0, max2 = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (digit > max1) {
                max2 = max1;
                max1 = digit;
            } else if (digit > max2) {
                max2 = digit;
            }
        }
        return max1 * max2;
    }
};