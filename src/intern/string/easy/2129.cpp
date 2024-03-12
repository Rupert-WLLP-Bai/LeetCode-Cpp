#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 2129. 首字母大写
     *
     * @param title
     * @return string
     */
    string capitalizeTitle(string title) {
        // split title by space
        istringstream iss(title);
        string word;
        string res;
        // if length of word is 1 or 2, make it lowercase
        // else capitalize the first letter, and make the rest lowercase
        while (iss >> word) {
            if (word.length() == 1 || word.length() == 2) {
                for (auto &c : word) {
                    c = tolower(c);
                }
            } else {
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.length(); i++) {
                    word[i] = tolower(word[i]);
                }
            }
            res += word + " ";
        }
        res.pop_back();
        return res;
    }
};

int main() {
    string title = "capiTalIze tHe titLe";
    Solution s;
    cout << s.capitalizeTitle(title) << endl;
    return 0;
}
