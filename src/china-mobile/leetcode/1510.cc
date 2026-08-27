#include <vector>
using namespace std;

class Solution {
  public:
    bool winnerSquareGame(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (!f[i - k * k]) f[i] = 1;
            }
        }
        return f[n];
    }
};