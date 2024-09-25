#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * @brief LC 295. 数据流的中位数
 *
 */
class MedianFinder {
  public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }

  private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl;
    return 0;
}