#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 290 单词规律
     *
     * @param pattern
     * @param s
     * @return true
     * @return false
     */
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> words;
        string word;
        // strip words from s
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }
        // check if the length of pattern and words are equal
        if (pattern.size() != words.size()) {
            return false;
        }
        // check if the pattern and words are one-to-one mapping
        for (int i = 0; i < pattern.size(); i++) {
            if (m1.count(pattern[i]) && m1[pattern[i]] != words[i]) {
                return false;
            }
            if (m2.count(words[i]) && m2[words[i]] != pattern[i]) {
                return false;
            }
            m1[pattern[i]] = words[i];
            m2[words[i]] = pattern[i];
        }
        return true;
    }
};

int main() {
    vector<string> patterns = {"abba", "abba", "aaaa", "abba"};
    vector<string> ss = {"dog cat cat dog", "dog cat cat fish",
                         "dog dog dog dog", "dog cat cat dog"};
    Solution solution;
    for (int i = 0; i < patterns.size(); i++) {
        cout << solution.wordPattern(patterns[i], ss[i]) << endl;
    }
    return 0;
}