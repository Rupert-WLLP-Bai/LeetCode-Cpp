#include "../../../../include/list.h"
#include <iostream>

class Solution {
  public:
    /**
     * @brief LC 24. 两两交换链表中的节点
     *
     * @param head
     * @return ListNode*
     */
    ListNode *swapPairs(ListNode *head) {
        // if len == 0 or len == 1
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // loop and swap
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        auto l = head;

        // pick two nodes and swap
        while (l != nullptr && l->next != nullptr) {
            auto r = l->next;
            l->next = r->next;
            r->next = l;
            pre->next = r;
            pre = l;
            l = l->next;
        }

        // return the new head
        return dummy->next;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createList(arr);
    printList(head);
    head = Solution().swapPairs(head);
    printList(head);
    return 0;
}