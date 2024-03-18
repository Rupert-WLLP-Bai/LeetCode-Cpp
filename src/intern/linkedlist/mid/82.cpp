#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 82. 删除排序链表中的重复元素 II
     *
     * @param head
     * @return ListNode*
     */
    ListNode *deleteDuplicates(ListNode *head) {
        auto slow = head;
        auto fast = head;
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto prev = dummy;
        while (fast) {
            while (fast->next && fast->val == fast->next->val) {
                fast = fast->next;
            }
            if (slow != fast) {
                prev->next = fast->next;
                slow = fast->next;
            } else {
                prev = prev->next;
                slow = slow->next;
            }
            fast = slow;
        }
        return dummy->next;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5};
    ListNode *head = createList(nums);
    Solution s;
    printList(s.deleteDuplicates(head));
    return 0;
}