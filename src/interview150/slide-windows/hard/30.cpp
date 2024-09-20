#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 30. 串联所有单词的子串
     *
     * @param s
     * @param words
     * @return vector<int>
     */
    vector<int> findSubstring(string s, vector<string> &words) {
        // 首先判断特殊情况
        if (s.empty() || words.empty()) {
            return {};
        }
        // 初始化结果数组
        vector<int> res;
        // 初始化单词数组
        unordered_map<string, int> wordMap;
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]]++; // 将单词放入map中 key为单词
                                 // value为单词出现的次数
        }
        // 初始化单词的长度
        int wordLen = words[0].size();
        // 初始化单词的个数
        int wordNum = words.size();
        // 初始化单词的总长度
        int totalLen = wordLen * wordNum;
        // 遍历字符串
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int>
                window; // 初始化窗口, key为单词 value为单词出现的次数
            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                if (wordMap.find(word) == wordMap.end()) {
                    count = 0;
                    left = right;
                    window.clear();
                } else {
                    window[word]++;
                    count++;
                    while (window[word] > wordMap[word]) {
                        string temp = s.substr(left, wordLen);
                        count--;
                        window[temp]--;
                        left += wordLen;
                    }
                    if (count == wordNum) {
                        res.push_back(left);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> res = s.findSubstring(str, words);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}