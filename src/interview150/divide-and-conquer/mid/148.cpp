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
     * @brief LC 148. 排序链表
     *
     * @param head
     * @return ListNode*
     */
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        auto dummy = new ListNode(0);
        dummy->next = head;
        for (int subLen = 1; subLen < len; subLen <<= 1) {
            ListNode *prev = dummy;
            ListNode *cur = dummy->next;
            while (cur) {
                ListNode *head1 = cur;                // 第一段的头节点
                ListNode *head2 = cut(head1, subLen); // 第二段的头节点
                cur = cut(head2, subLen); // 更新 cur 为下一段的头节点
                prev->next = merge(head1, head2); // 合并两段有序链表
                while (prev->next) {
                    prev = prev->next; // 更新 prev 为合并后的链表的尾节点
                }
            }
        }
        return dummy->next;
    }

  private:
    /**
     * @brief 合并两个有序链表 l1 和 l2
     *
     * @param l1
     * @param l2
     * @return ListNode*
     */
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return dummy.next;
    }

    /**
     * @brief 切断链表 head 后 n 个节点，并返回剩余部分的头节点
     *
     * @param head
     * @param n
     * @return ListNode*
     */
    ListNode *cut(ListNode *head, int n) {
        while (--n && head) {
            head = head->next;
        }
        if (!head) {
            return nullptr;
        }
        ListNode *next = head->next;
        head->next = nullptr;
        return next;
    }
};

int main() {
    Solution sol;
    ListNode *head = createList({4, 2, 1, 3});
    cout << "Before sort: " << endl;
    printList(head);
    ListNode *res = sol.sortList(head);
    cout << "After sort: " << endl;
    printList(res);
}