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
     * @brief LC 21. 合并两个有序链表
     *
     * @param list1
     * @param list2
     * @return ListNode*
     */
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(-1); // 哑节点 便于处理头节点
        ListNode *cur = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 == nullptr ? list2 : list1;
        return dummy->next;
    }
};

int main() {
    Solution solution = Solution();
    ListNode *list1 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    list1->next = node1;
    node1->next = node2;

    ListNode *list2 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    list2->next = node3;
    node3->next = node4;

    ListNode *result = solution.mergeTwoLists(list1, list2);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}