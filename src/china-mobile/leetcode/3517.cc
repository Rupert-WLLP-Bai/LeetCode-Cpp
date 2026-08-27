#include <string>

using namespace std;

class Solution {
  public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int half = n / 2;
        int cnt[26] = {0};

        // 第一步：统计前半段字符频次 —— O(n/2)
        for (int i = 0; i < half; ++i) {
            ++cnt[s[i] - 'a'];
        }

        // 第二步：从小到大填回 s 的左右镜像位置 —— O(n/2)
        int idx = 0;
        for (int c = 0; c < 26; ++c) {
            while (cnt[c] > 0) {
                s[idx] = 'a' + c;
                s[n - 1 - idx] = 'a' + c;
                ++idx;
                --cnt[c];
            }
        }
        // 奇数长度时，s[half] 本身就没被覆盖，自动保留
        return s;
    }
};