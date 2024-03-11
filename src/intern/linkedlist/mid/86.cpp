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
    }

  private:
    vector<int> getIndex(ListNode *head, int x) {
        vector<int> res;
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