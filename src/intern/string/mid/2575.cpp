#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2575. 找出字符串的可整除数组
     *
     * @param word
     * @param m
     * @return vector<int>
     */
    vector<int> divisibilityArray(string word, int m) {
        // 每次取出一位, 计算下一个之前先乘10取余
        int n = word.size();
        vector<int> result(n, 0);
        long long num = 0;
        for (int i = 0; i < n; i++) {
            num = (num * 10 + word[i] - '0') % m;
            if (num == 0) {
                result[i] = 1;
            } else {
                result[i] = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"998244353", "1010"};
    vector<int> m = {3, 10};
    for (int i = 0; i < words.size(); i++) {
        vector<int> result = solution.divisibilityArray(words[i], m[i]);
        for (int j = 0; j < result.size(); j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}