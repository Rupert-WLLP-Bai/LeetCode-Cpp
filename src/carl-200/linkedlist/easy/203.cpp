#include <iostream>
#include "../../../../include/list.h"
class Solution {
  public:
    /**
     * @brief LC 203. 移除链表元素
     *
     * @param head
     * @return ListNode*
     */
    ListNode *removeElements(ListNode *head, int val) {
        // set a dummy head to simplify deleting
        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;
        // start from the dummy head
        auto cur = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                // delele this node
                auto tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        auto newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};

int main() {
    Solution s;
    std::vector<int> arr = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = createList(arr);
    printList(head);
    ListNode *res = s.removeElements(head, 6);
    printList(res);
    return 0;
}