#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 461. 汉明距离
     *
     * @param x
     * @param y
     * @return int
     */
    int hammingDistance(int x, int y) {
        // 按位异或，不同的位为 1
        int z = x ^ y;
        int res = 0;
        // 统计 1 的个数
        while (z) {
            res += z & 1; // z & 1 可以判断 z 的最低位是否为 1
            z >>= 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.hammingDistance(1, 4) << endl;
    return 0;
}