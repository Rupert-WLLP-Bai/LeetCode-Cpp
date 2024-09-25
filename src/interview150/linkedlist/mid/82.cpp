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
     * @brief LC 82. 删除排序链表中的重复元素 II
     *
     * @param head
     * @return ListNode*
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // at least 2 nodes
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto prev = dummy;
        auto curr = head;

        while (curr != nullptr) {
            bool isDuplicate = false;
            while (curr->next != nullptr && curr->val == curr->next->val) {
                isDuplicate = true;
                auto temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }

            if (isDuplicate) {
                // delete curr
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr; // move prev to curr
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5};
    ListNode *head = createList(nums);
    Solution solution = Solution();
    ListNode *result = solution.deleteDuplicates(head);
    printList(result);
}