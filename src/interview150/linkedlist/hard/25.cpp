#include "../../../../include/core.h"

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
     * @brief LC 25. K 个一组翻转链表
     *
     * @param head
     * @param k
     * @return ListNode*
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto len = 0;
        auto p = head;
        while (p) {
            len++;
            p = p->next;
        }
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        while (len >= k) {
            auto cur = pre->next;
            for (int i = 0; i < k - 1; i++) {
                auto temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            len -= k;
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
    ListNode *res = sol.reverseKGroup(head, 2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}