#include "../../../../include/core.h"

using namespace std;

class Solution {
  public:
    /**
     * @brief LC 23. 合并K个升序链表
     *
     * @param lists
     * @return ListNode*
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // 把节点放入优先队列中，自动排序
        auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (auto &head : lists) {
            if (head) {
                pq.push(head);
            }
        }
        ListNode dummy(0);       // 使用一个哑节点
        ListNode *tail = &dummy; // 使用一个尾指针
        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};

int main() {
    vector<ListNode *> lists;
    vector<int> l1 = {1, 4, 5};
    vector<int> l2 = {1, 3, 4};
    vector<int> l3 = {2, 6};
    ListNode *head1 = createList(l1);
    ListNode *head2 = createList(l2);
    ListNode *head3 = createList(l3);
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    Solution s;
    ListNode *res = s.mergeKLists(lists);
    printList(res);
    return 0;
}