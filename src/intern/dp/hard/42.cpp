#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 42. 接雨水
     *
     * @param height
     * @return int
     */
    int trap(vector<int> &height) {
        stack<int> st; // 存放下标
        int sum = 0;   // 总和结果

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top(); // 当前栈顶 表示凹陷的位置
                st.pop(); // 弹出栈顶 现在栈顶表示左边的最高位置
                if (!st.empty()) {
                    int left = st.top(); // 左边最高位置
                    int h = min(height[left], height[i]) - height[top];
                    int w = i - left - 1;
                    sum += h * w;
                }
            }
            st.push(i); // 将当前位置入栈
        }
        return sum;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}
