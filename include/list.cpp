#include "list.h"

void printList(ListNode *head) {
    auto p = head;
    while (p != nullptr) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "null" << endl;
}

ListNode *createList(const std::vector<int> &arr) {
    ListNode *head = new ListNode(-1);
    auto p = head;
    for (auto i : arr) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return head->next;
}