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
    ListNode *partition(ListNode *head, int x) {
        // 处理后的节点数组
        auto vec = process(head, x);

        // 新建一个虚拟头节点
        auto dummy = new ListNode(0);
        auto p = dummy;

        // 将所有节点按顺序连接
        for (auto &&node : vec) {
            p->next = node;
            p = p->next;
        }

        // 最后一个节点的 next 应指向 nullptr，避免链表环
        p->next = nullptr;

        return dummy->next;
    }

  private:
    vector<ListNode *> process(ListNode *head, int x) {
        auto vec1 = vector<ListNode *>(); // 保存小于x的节点
        auto vec2 = vector<ListNode *>(); // 保存大于等于x的节点

        auto p = head;

        // 正确的遍历链表条件
        while (p != nullptr) {
            // 按条件分类存储
            if (p->val < x) {
                vec1.push_back(p);
            } else {
                vec2.push_back(p);
            }

            // 移动到下一个节点
            p = p->next;
        }

        // 将两个 vector 合并
        auto res = vector<ListNode *>(vec1.size() + vec2.size());
        copy(vec1.begin(), vec1.end(), res.begin());
        copy(vec2.begin(), vec2.end(), res.begin() + vec1.size());

        // 断开所有节点的 next，避免链表环
        for (auto &&node : res) {
            node->next = nullptr;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 4, 3, 2, 5, 2};
    ListNode *head = createList(nums);
    Solution solution = Solution();
    ListNode *result = solution.partition(head, 3);
    printList(result);
}