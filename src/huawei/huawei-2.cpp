#include <iostream>
#include <locale>
#include <string>
#include <vector>

using namespace std;

// 第一行输入 第一个输入m 表示列表长度 第二个输入n 表示时刻树
// 第二行输入m个数 表示列表
// 计算出一个最小的和 使得第二行的输入可以拆解为n个列表，其中每个列表的和都不超过这个最小和
int calc(int m, int n, vector<int> list){
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += list[i];
    }
    int avg = sum / n;
    int min = avg;
    while (true) {
        int count = 0;
        int temp = 0;
        for (int i = 0; i < m; ++i) {
            temp += list[i];
            if (temp > min) {
                temp = list[i];
                ++count;
            }
        }
        if (count < n) {
            break;
        }
        ++min;
    }
    return min;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<int> list;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    cout << calc(m, n, list) << endl;
}