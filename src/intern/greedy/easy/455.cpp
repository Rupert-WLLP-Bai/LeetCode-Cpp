#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 455. 分发饼干
     *
     * @param g
     * @param s
     * @return int
     */
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0; // g children
        int j = 0; // s biscuits
        while (i != g.size() && j != s.size()) {
            if (g[i] <= s[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i;
    }
};

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    Solution s1;
    cout << s1.findContentChildren(g, s) << endl;
    return 0;
}