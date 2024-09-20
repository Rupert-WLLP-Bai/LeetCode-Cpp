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
     * @brief LC 19. 删除链表的倒数第 N 个结点
     *
     * @param head
     * @param n
     * @return ListNode*
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        // 快慢指针
        auto fast = dummy;
        auto slow = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除倒数第 n 个节点
        auto temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy->next;
    }
};

int main() {
    Solution sol;
    ListNode *head = createList({1, 2, 3, 4, 5});
    ListNode *res = sol.removeNthFromEnd(head, 2);
    printList(res);
}