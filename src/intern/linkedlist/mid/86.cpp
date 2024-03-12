#include "../../../../include/list.h"
#include <iostream>
#include <vector>

class Solution {
  public:
    /**
     * @brief LC 86. 分隔链表
     *
     * @param head
     * @param x
     * @return ListNode*
     */
    ListNode *partition(ListNode *head, int x) {
        if (!head) {
            return head;
        }
        vector<ListNode *> v = getIndex(head, x);
        for (int i = 0; i < v.size() - 1; i++) {
            v[i]->next = v[i + 1];
        }
        v[v.size() - 1]->next = nullptr;
        return v[0];
    }

  private:
    vector<ListNode *> getIndex(ListNode *head, int x) {
        // 先保存所有小于x的节点
        ListNode *p = head;
        vector<ListNode *> v;
        while (p) {
            if (p->val < x) {
                v.push_back(p);
            }
            p = p->next;
        }
        // 再将所有大于等于x的节点添加到v中
        p = head;
        while (p) {
            if (p->val >= x) {
                v.push_back(p);
            }
            p = p->next;
        }
        return v;
    }
};

int main() {
    vector<int> arr = {1, 4, 3, 2, 5, 2};
    ListNode *head = createList(arr);
    printList(head);
    head = Solution().partition(head, 3);
    printList(head);
    return 0;
}