#include "../../../../include/core.h"
using namespace std;

class Solution {
  public:
    /**
     * @brief LC 148. 排序链表
     *
     * @param head
     * @return ListNode*
     */
    ListNode *sortList(ListNode *head) {
        vector<int> vec;
        ListNode *dummy = new ListNode(0);
        auto p1 = head;
        while (p1) {
            vec.push_back(p1->val);
            p1 = p1->next;
        }
        sort(vec.begin(), vec.end());
        auto p2 = dummy;
        for (auto num : vec) {
            ListNode *node = new ListNode(num);
            p2->next = node;
            p2 = p2->next;
        }
        return dummy->next;
    }
};

int main() {
    vector<int> nums = {4, 2, 1, 3};
    ListNode *head = createList(nums);
    Solution solution;
    ListNode *result = solution.sortList(head);
    printList(result);
    return 0;
}