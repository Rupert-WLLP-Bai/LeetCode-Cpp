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
     * @brief LC 61. 旋转链表
     *
     * @param head
     * @param k
     * @return ListNode*
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = 1;
        auto p = head;
        while (p->next != nullptr) {
            p = p->next;
            len++;
        }
        p->next = head;    // 首尾相连
        k = len - k % len; // 右移k位等价于左移len-k位
        for (int i = 0; i < k; i++) {
            p = p->next;
        }
        // 更改头尾指针
        head = p->next;
        p->next = nullptr;
        return head;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    Solution solution = Solution();
    ListNode *result = solution.rotateRight(head, 2);
    printList(result);
}