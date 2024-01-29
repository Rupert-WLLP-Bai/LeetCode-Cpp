#include <iostream>
#include <locale>
#include <string>
#include <vector>

using namespace std;

// sum[n]
// 第一行输入 n
// 第二行输入 nums[n]
// 第三行输入 r 表示 sum[n] = nums[n] + nums[n-1] + ... + nums[n-r] + nums[n+1] + ... + nums[n+r]
// (注意不要越界)
// 第四行输入 add 可以把 add 分配到nums[n]上的任意多个位置 可以拆开分配
// 使得 min(sum[n]) 最大
// 输出 min(sum[n])
int calc(int n, vector<int> nums, int r, int add) {
    vector<int> sum;
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        for (int j = i - r; j <= i + r; ++j) {
            if (j >= 0 && j < n) {
                temp += nums[j];
            }
        }
        sum.push_back(temp);
    }
    int min = sum[0];
    for (int i = 1; i < n; ++i) {
        if (sum[i] < min) {
            min = sum[i];
        }
    }
    return min + add;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int r;
    cin >> r;
    int add;
    cin >> add;

    cout << calc(n, nums, r, add) << endl;
}