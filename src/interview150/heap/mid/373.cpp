#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 373. 查找和最小的K对数字
     *
     * @param nums1
     * @param nums2
     * @param k
     * @return vector<vector<int>>
     */
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                       int k) {
        typedef pair<int, pair<int, int>> Node;
        auto cmp = [](Node &a, Node &b) { return a.first > b.first; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        // 不放入所有的元素
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        vector<vector<int>> res;
        while (k-- && !pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int i = node.second.first;
            int j = node.second.second;
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> res = solution.kSmallestPairs(nums1, nums2, k);
    for (auto &v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}