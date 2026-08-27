#include <cstdlib>
#include <vector>

using std::vector;

class Solution {
  public:
    bool stoneGameIX(vector<int> &stones) {
        vector<int> mods(3, 0);
        for (auto i : stones) {
            ++mods[i % 3];
        }
        if (mods[0] % 2 == 0) {
            return mods[1] > 0 && mods[2] > 0;
        } else {
            return abs(mods[1] - mods[2]) > 2;
        }
    }
};