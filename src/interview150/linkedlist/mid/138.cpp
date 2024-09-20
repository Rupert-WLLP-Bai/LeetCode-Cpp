#include "../../../../include/core.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    /**
     * @brief LC 138. 随机链表的复制
     *
     * @param head
     * @return Node*
     */
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> m; // key: old | value: new
        auto p = head;
        auto dummy = new Node(-1);
        auto cur = dummy;
        while (p != nullptr) {
            auto new_node = new Node(p->val);
            m[p] = new_node;
            cur->next = new_node;
            cur = cur->next;
            p = p->next;
        }

        p = head;
        cur = dummy->next;
        while (p != nullptr) {
            cur->random = m[p->random];
            p = p->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution solution = Solution();
    Node *head = new Node(7);
    Node *node1 = new Node(13);
    Node *node2 = new Node(11);
    Node *node3 = new Node(10);
    Node *node4 = new Node(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node1->random = head;
    node2->random = node4;
    node3->random = node2;
    node4->random = head;
    Node *result = solution.copyRandomList(head);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}