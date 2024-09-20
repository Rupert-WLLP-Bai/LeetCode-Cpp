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
     * @brief LC 2. 两数相加
     *
     * @param l1
     * @param l2
     * @return ListNode*
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1); // 哑节点 便于处理头节点
        ListNode *cur = dummy;
        int carry = 0; // 进位
        while (l1 != nullptr || l2 != nullptr) {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

int main() {
    Solution solution = Solution();
    ListNode *l1 = new ListNode(2);
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(3);
    l1->next = node1;
    node1->next = node2;

    ListNode *l2 = new ListNode(5);
    ListNode *node3 = new ListNode(6);
    ListNode *node4 = new ListNode(4);
    l2->next = node3;
    node3->next = node4;

    ListNode *result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}