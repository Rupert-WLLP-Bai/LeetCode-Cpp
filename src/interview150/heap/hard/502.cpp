#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 502. IPO
     *
     * @param k
     * @param w
     * @param profits
     * @param capital
     * @return int
     */
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital) {
        typedef pair<int, int> Node;
        auto cmp = [](Node &a, Node &b) {
            return a.first < b.first;
        }; // 按照利润排序
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        // 按照资本排序
        sort(projects.begin(), projects.end());
        int i = 0;
        // 选择k个项目
        while (k--) {
            // 选择所有满足资本的项目 由于已经按照资本排序 所以只需要遍历一次
            while (i < projects.size() && projects[i].first <= w) {
                pq.push({projects[i].second, projects[i].first});
                i++;
            }
            // 选择利润最大的项目
            if (!pq.empty()) {
                w += pq.top().first;
                pq.pop();
            } else {
                break;
            }
        }
        return w;
    }
};

int main() {
    Solution solution;
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    cout << solution.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}