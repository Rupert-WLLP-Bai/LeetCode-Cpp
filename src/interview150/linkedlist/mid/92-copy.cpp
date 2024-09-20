#include "../../../../include/core.h"
#include "list.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    /**
     * @brief LC 92 反转链表 II
     *
     * @param head
     * @param left
     * @param right
     * @return ListNode*
     */
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        auto cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            // pre -> cur -> cur.next -> cur.next.next
            auto temp = cur->next;
            cur->next = temp->next;
            // pre -> cur -> cur.next.next <- cur.next
            temp->next = pre->next;
            // cur.next -> cur -> cur.next.next
            // pre -> cur -> cur.next.next
            pre->next = temp;
            // pre -> cur.next -> cur -> cur.next.next
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 2; i <= 5; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    ListNode *res = sol.reverseBetween(head, 2, 4);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}