#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 202. 快乐数
     *
     * @param n
     * @return true
     * @return false
     */
    bool isHappy(int n) {
        unordered_set<int> uset;
        while (true) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (uset.find(sum) != uset.end()) {
                return false;
            }
            uset.insert(sum);
            n = sum;
        }
    }

  private:
    int getSum(int n) {
        int res = 0;
        int rest = n;
        int cur = 0;
        while (rest != 0) {
            cur = rest % 10;
            rest /= 10;
            res += cur * cur;
        }
        // cout << "sum of " << n << " is : " << res << endl;
        return res;
    }
};

int main() {
    int n = 19;
    Solution s;
    cout << s.isHappy(n) << endl;
    return 0;
}