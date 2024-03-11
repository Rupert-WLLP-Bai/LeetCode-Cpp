#include "../../../../include/list.h"
#include <iostream>

class Solution {
  public:
    /**
     * @brief LC 19. 删除链表的倒数第 N 个结点
     *
     * @param head
     * @param n
     * @return ListNode*
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // fast and slow pointers
        auto fast = head;
        auto slow = head;
        while (n--) {
            fast = fast->next;
        }

        // delete the first one
        if (fast == nullptr) {
            auto res = slow->next;
            delete slow;
            return res;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // delete the node after slow pointer
        auto tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return head;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode *head = createList(arr);
    printList(head);
    head = Solution().removeNthFromEnd(head, n);
    printList(head);
    return 0;
}