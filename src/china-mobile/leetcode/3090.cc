#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int maximumLengthSubstring(string s) {
        const int N = 2;
        unordered_map<char, int> m;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            ++m[s[right]];
            while (m[s[right]] > N) {
                --m[s[left]];
                ++left;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};