#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 92. 反转链表 II
     *
     * @param head
     * @param left
     * @param right
     * @return ListNode*
     */
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    Solution solution;
    ListNode *result = solution.reverseBetween(head, 2, 4);
    printList(result);
}