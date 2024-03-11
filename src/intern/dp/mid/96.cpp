#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 96. 不同的二叉搜索树
     *
     * @param n
     * @return int
     */
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        dp[0] = 1; // 0 个节点的二叉搜索树有 1 种
        dp[1] = 1; // 1 个节点的二叉搜索树有 1 种
        dp[2] = 2; // 2 个节点的二叉搜索树有 2 种

        // 每次取一个节点作为根节点，依次累加 左子树 * 右子树 的数量
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j]; // 左子树 * 右子树
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.numTrees(3) << endl;
    cout << s.numTrees(1) << endl;
    return 0;
}