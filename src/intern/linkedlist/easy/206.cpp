#include <iostream>
#include "../../../../include/list.h"

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 206. 反转链表
     *
     * @param head
     * @return ListNode*
     */
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        auto l = head;
        auto m = head;
        auto r = head;
        m = head->next;
        r = head->next;

        // case 1 : len == 1
        if (m == nullptr) {
            return l;
        }

        r = r->next;
        // reverse and loop
        while (r != nullptr) {
            m->next = l;
            l = m;
            m = r;
            r = r->next;
        }
        // m becomes the last node
        m->next = l;

        // change the head->next to nullptr
        head->next = nullptr;

        // return the new head (last node of the original list)
        return m;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createList(arr);
    printList(head);
    head = Solution().reverseList(head);
    printList(head);
    return 0;
}