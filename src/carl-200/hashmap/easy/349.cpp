#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 349. 两个数组的交集
     *
     * @param nums1
     * @param nums2
     * @return vector<int>
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> uset;
        unordered_set<int> res;
        for (auto num : nums1) {
            uset.insert(num);
        }
        for (auto num : nums2) {
            // can be found in uset
            if (uset.find(num) != uset.end()) {
                res.insert(num);
            } else {
                // skip this
                continue;
            }
        }
        // convert res to vector
        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    vector<vector<int>> nums1 = {{1, 2, 2, 1}, {4, 9, 5}};
    vector<vector<int>> nums2 = {{2, 2}, {9, 4, 9, 8, 4}};
    Solution s;
    for (int i = 0; i < nums1.size(); i++) {
        cout << "nums1: ";
        for (auto n : nums1[i]) {
            cout << n << " ";
        }
        cout << "nums2: ";
        for (auto n : nums2[i]) {
            cout << n << " ";
        }
        cout << " result: ";
        for (auto n : s.intersection(nums1[i], nums2[i])) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}