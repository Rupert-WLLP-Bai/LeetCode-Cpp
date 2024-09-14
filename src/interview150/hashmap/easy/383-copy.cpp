#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 383. 赎金信
     *
     * @param ransomNote
     * @param magazine
     * @return true
     * @return false
     */
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (auto s : magazine) {
            mag[s]++;
        }

        for (auto c : ransomNote) {
            if (--mag[c] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<string> ransomNotes = {"a", "aa", "aa"};
    vector<string> magazines = {"b", "ab", "aab"};
    Solution s;
    for (int i = 0; i < ransomNotes.size(); i++) {
        cout << "ransomNote: " << ransomNotes[i]
             << " magazine: " << magazines[i]
             << " result: " << s.canConstruct(ransomNotes[i], magazines[i])
             << endl;
    }
    return 0;
}