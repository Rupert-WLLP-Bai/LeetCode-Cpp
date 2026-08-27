#include <algorithm>
using namespace std;

class Solution {
  public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        // 分别计算两个矩形的面积
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        // 计算两个矩形的交集面积
        // 上下左右边界
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int overlapArea = max(0, right - left) * max(0, top - bottom);
        // 返回两个矩形的面积之和减去交集面积
        return area1 + area2 - overlapArea;
    }
};