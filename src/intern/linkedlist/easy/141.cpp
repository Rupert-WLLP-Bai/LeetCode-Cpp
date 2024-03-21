#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 141. 环形链表
     *
     * @param head
     * @return true
     * @return false
     */
    bool hasCycle(ListNode *head) {
        // 快慢指针
        auto fast = head;
        auto slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto *obj = new Solution();
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout << boolalpha << obj->hasCycle(head) << endl;
    return 0;
}