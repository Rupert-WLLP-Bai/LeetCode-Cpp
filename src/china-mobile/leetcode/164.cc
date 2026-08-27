#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
  public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        if (mn == mx) return 0;

        // 桶大小 = ceil((mx - mn) / (n - 1)), 至少为 1
        int bucketSize = max(1, (mx - mn) / (n - 1));
        int bucketCnt  = (mx - mn) / bucketSize + 1;

        // 每个桶只存 min / max, 用 INT_MAX/-1 标记空桶
        vector<int> bMin(bucketCnt, INT_MAX);
        vector<int> bMax(bucketCnt, INT_MIN);

        for (int x : nums) {
            int idx = (x - mn) / bucketSize;
            bMin[idx] = min(bMin[idx], x);
            bMax[idx] = max(bMax[idx], x);
        }

        // 桶 0 一定非空 (mn 在里面), 从它出发扫
        int maxGap  = 0;
        int prevMax = bMax[0];
        for (int i = 1; i < bucketCnt; i++) {
            if (bMin[i] == INT_MAX) continue; // 空桶
            maxGap  = max(maxGap, bMin[i] - prevMax);
            prevMax = bMax[i];
        }
        return maxGap;
    }
};