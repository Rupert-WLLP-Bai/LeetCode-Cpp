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
     * @brief LC 23. 合并K个升序链表
     *
     * @param lists
     * @return ListNode*
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);
    }

    /**
     * @brief 合并多个有序链表
     *
     * @param lists
     * @param l 表示链表在lists中的左边界索引
     * @param r 表示链表在lists中的右边界索引
     * @return ListNode*
     */
    ListNode *merge(vector<ListNode *> &lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        auto l1 = merge(lists, l, mid);
        auto l2 = merge(lists, mid + 1, r);
        return mergeTwoLists(l1, l2);
    }

    /**
     * @brief 合并两个有序链表
     *
     * @param l1
     * @param l2
     * @return ListNode*
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2; // l1和l2中有一个已经遍历完
        return dummy->next;
    }
};

int main() {
    Solution sol;
    vector<ListNode *> lists = {createList({1, 4, 5}), createList({1, 3, 4}),
                                createList({2, 6})};
    ListNode *res = sol.mergeKLists(lists);
    printList(res);
    return 0;
}