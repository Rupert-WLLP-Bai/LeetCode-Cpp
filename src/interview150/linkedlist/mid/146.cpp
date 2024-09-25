#include "../../../../include/core.h"

using namespace std;

/**
 * @brief LC 146. LRU 缓存
 *
 */
class LRUCache {
  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // 首先在哈希表中查找 key
        auto it = map.find(key);
        // 如果 key 不存在，直接返回 -1
        if (it == map.end()) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到链表头部
        auto kv = *map[key];
        cache.erase(map[key]);    // 删除旧的节点
        cache.push_front(kv);     // 将新节点插入链表头部
        map[key] = cache.begin(); // 更新 (key, value) 在 cache 中的位置
        return kv.second;
    }

    void put(int key, int value) {
        // 首先在哈希表中查找 key
        auto it = map.find(key);
        // 如果 key 不存在
        if (it == map.end()) {
            // 如果缓存满了
            if (cache.size() == capacity) {
                // 删除链表尾部节点
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey); // 删除哈希表中该节点
                cache.pop_back();   // 删除链表尾部节点
            }
            // 插入新节点到链表头部
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到链表头部
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }

  private:
    int capacity;                                           // 容量
    list<pair<int, int>> cache;                             // 双向链表
    unordered_map<int, list<pair<int, int>>::iterator> map; // 哈希表
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
}
