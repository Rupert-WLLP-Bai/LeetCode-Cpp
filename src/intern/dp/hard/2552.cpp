#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    long long countQuadruplets(vector<int> &nums) {
        long long res = 0;
        auto n = nums.size();
        // (i) -> j -> (k) -> l
        // i < j < k < l
        // nums[i] < nums[k] < nums[j] < nums[l]
        //    1        3        2        4
        // v21[i2][i1] nums[x] < nums[i2] x exists in [0, i1)
        // v32[i3][i2] nums[x] > nums[i3] x exists in [0, i2)

        vector<vector<int>> v21(n, vector<int>(n, 0));
        vector<vector<int>> v32(n, vector<int>(n, 0));

        // form up 1 3
        for (int i2 = 1; i2 < n; i2++) {
            for (int i1 = 0; i1 < i2; i1++) {
                // i1 < i2 and nums[i1] < nums[i2]
                if (i1 == 0) {
                    v21[i2][i1] = 0;
                    continue;
                }
                if (i1 < i2 && nums[i1] < nums[i2]) {
                    v21[i2][i1] = v21[i2 - 1][i1 - 1] + 1;
                } else {
                    v21[i2][i1] = v21[i2 - 1][i1 - 1];
                }
            }
        }
        // v21 [i,j] 表示 nums[x] < nums[i] 的个数, x in [0, j)

        // form up 1 3 2
        for (int i3 = 2; i3 < n; i3++) {
            for (int i2 = 1; i2 < i3; i2++) {
                if (i2 < i3 && nums[i2] < nums[i3]) {
                    v32[i3][i2] =
                        v32[i3 - 1][i2] +
                        v21[i2][i2 - 1]; // 同时满足 nums[x] > nums[i3] &&
                                         // nums[x] < nums[i2]
                } else {
                    v32[i3][i2] = v32[i3 - 1][i2];
                }
            }
        }
        // v32 [i,j] 表示 nums[i3] < nums[x] < nums[i2] 的个数, x in [0, j)

        // form up 1 3 2 4
        for (int i4 = 3; i4 < n; i4++) {
            for (int i2 = 1; i2 < i4; i2++) {
                if (i2 < i4 && nums[i2] < nums[i4]) {
                    res += v32[i4 - 1][i2];
                }
            }
        }
        // 最后找到比nums[i2]大的个数

        return res;
    }
};

class SolutionLeetcode {
  public:
    long long countQuadruplets(vector<int> &nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int suf = 0;
            for (int k = n - 1; k > j; --k) {
                if (nums[j] > nums[k]) {
                    ans += static_cast<long long>(pre[nums[k]]) * suf;
                } else {
                    ++suf;
                }
            }
            for (int x = nums[j] + 1; x <= n; ++x) {
                ++pre[x];
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums = {2, 5, 3, 1, 4};
    cout << solution.countQuadruplets(nums) << endl;
    nums = {1, 3, 2, 4, 5};
    cout << solution.countQuadruplets(nums) << endl;
    return 0;
}