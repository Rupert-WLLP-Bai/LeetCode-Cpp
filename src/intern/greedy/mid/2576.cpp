#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        return 0;
    }
};

int main() {
    vector<vector<int>> testcases = {{3, 5, 2, 4}, {9, 2, 5, 4}, {7, 6, 8}};
    Solution sln;
    for (auto &testcase : testcases) {
        cout << "testcase: ";
        for (auto &num : testcase) {
            cout << num << " ";
        }
        cout << endl;
        cout << "result: " << sln.maxNumOfMarkedIndices(testcase) << endl;
        cout << endl;
    }
    return 0;
}