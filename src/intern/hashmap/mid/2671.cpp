#include "../../../../include/core.h"
using namespace std;

/**
 * @brief LC 2671. 频率跟踪器
 *
 */
class FrequencyTracker {
  public:
    FrequencyTracker() {
    }

    void add(int number) {
        // 如果数字已存在，则先降低当前频率的计数
        if (freq[number] > 0) {
            freqCount[freq[number]]--;
        }

        // 增加数字的频率
        freq[number]++;

        // 增加新频率的计数
        freqCount[freq[number]]++;
    }

    void deleteOne(int number) {
        // 如果数字的频率大于零
        if (freq[number] > 0) {
            // 降低当前频率的计数
            freqCount[freq[number]]--;

            // 减少数字的频率
            freq[number]--;

            // 只有当数字的新频率大于零时才增加计数
            if (freq[number] > 0) {
                freqCount[freq[number]]++;
            }
        }
    }

    bool hasFrequency(int frequency) {
        // 检查频率表中是否有大于零的计数
        return freqCount.find(frequency) != freqCount.end() &&
               freqCount[frequency] > 0;
    }

  private:
    std::unordered_map<int, int> freq;      // 存储每个数字的频率
    std::unordered_map<int, int> freqCount; // 存储每个频率有多少数字
};

int main() {
    auto *obj = new FrequencyTracker();
    obj->deleteOne(2);
    obj->deleteOne(1);
    obj->add(1);
    cout << boolalpha << obj->hasFrequency(1) << endl;
    cout << boolalpha << obj->hasFrequency(1) << endl;
    cout << boolalpha << obj->hasFrequency(1) << endl;
    delete obj;
    return 0;
}