#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        // dp[i][j] = min(dp[i-1][j-1] + triangle[i][j],
        //                  dp[i-1][j] + triangle[i][j])
        // if j == 0  => dp[i][j] = dp[i-1][j] + trangle[i][j]
        // if j == layer => dp[i][j] = dp[i-1][j-1] + triangle[i][j]
        // dp[0][0] = triangle[0][0]
        auto n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1] + triangle[i][j],
                                   dp[i - 1][j] + triangle[i][j]);
                }
            }
        }

        // output the dp
        // for (auto &row : dp) {
        //     for (auto &num : row) {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main() {
    vector<vector<vector<int>>> testcases = {
        {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}},
        {{-10}},
        {{-1}, {2, 3}, {1, -1, -3}}};
    Solution sln;
    for (auto &testcase : testcases) {
        cout << "testcase: " << endl;
        for (auto &row : testcase) {
            for (auto &num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << "result: " << sln.minimumTotal(testcase) << endl;
        cout << endl;
    }
    return 0;
}