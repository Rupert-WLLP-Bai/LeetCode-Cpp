#include <iostream>
#include <string>
#include <vector>

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
        vector<int> mag(26, 0);
        for (auto s : magazine) {
            mag[s - 'a']++;
        }

        for (auto c : ransomNote) {
            if (--mag[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<string> ransomNote = {"a", "aa", "aa"};
    vector<string> magazine = {"b", "ab", "aab"};
    Solution s;
    for (int i = 0; i < ransomNote.size(); i++) {
        cout << "ransomNote: " << ransomNote[i] << " magazine: " << magazine[i]
             << " result: " << s.canConstruct(ransomNote[i], magazine[i])
             << endl;
    }
    return 0;
}