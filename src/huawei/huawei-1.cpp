#include <iostream>
#include <locale>
#include <string>
#include <unordered_map>

using namespace std;

// 三种字符本身的分数 r:1 g:2 b:3
// 和前1个相同 当前位置加1分
// 和前2个相同 当前位置加2分
// 和前3个相同 当前位置加3分
// rrrggb: 1+(1+1)+(1+2)+2+(2+1) + 3 = 14
int calc(string s) {
    auto size = s.size();
    const unordered_map<char, int> score_map = {{'r', 1}, {'g', 2}, {'b', 3}};
    int score = 0;
    for (int i = 0; i < size; ++i) {
        score += score_map.at(s[i]);
        if (i > 2 && s[i] == s[i - 3]){
            score += 3;
        } else if (i > 1 && s[i] == s[i - 2]) {
            score += 2;
        } else if (i > 0 && s[i] == s[i - 1]) {
            score += 1;
        }
    }
    return score;
}

int main() {
    string input; // 输入的字符串
    cin >> input;
    cout << calc(input) << endl;
    return 0;
}
