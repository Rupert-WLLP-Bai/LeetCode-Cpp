#include <iostream>
#include <string>

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
        int l = 0;
        int r = 0;
        while (true) {
            r = title.find(' ', l);
            if (r == string::npos) {
                break;
            }
            title[r + 1] = toupper(title[r + 1]);
            l = r + 1;
        }
        title[0] = toupper(title[0]);
        return title;
    }
};

int main() {
    string title = "i love you";
    Solution s;
    cout << s.capitalizeTitle(title) << endl;
    return 0;
}
