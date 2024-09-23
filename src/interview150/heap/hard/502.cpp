#include <iostream>
#include <vector>
#include <queue>
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