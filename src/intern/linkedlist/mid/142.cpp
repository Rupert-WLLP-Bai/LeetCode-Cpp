#include "../../../../include/list.h"
#include <iostream>

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 142: 环形链表 II
     *
     * @param head
     * @return ListNode*
     */
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针
        auto slow = head;
        auto fast = head;
        // 快指针每次移动两格 慢指针每次移动一格
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // 判断 是否相遇
            if (slow == fast) {
                // 如果相遇 则记录下当前位置
                // 此时定义一个指针从头节点出发
                // 再定义一个指针从当前位置出发
                // 相遇的位置就是环的入口
                auto p1 = slow;
                auto p2 = head;
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    ListNode *res = s.detectCycle(head);
    if (res == nullptr) {
        cout << "null" << endl;
    } else {
        cout << res->val << endl;
    }
    return 0;
}