#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;

    Node(int val, Node *next = nullptr, Node *prev = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

/**
 * @brief LC 707. 设计链表
 *
 */
class MyLinkedList {
  public:
    MyLinkedList() {
        // with dummy head
        head = new Node(-1);
        tail = head;
        head->next = tail;
        tail->prev = head;
        len = 0;
    }

    int get(int index) {
        if (len <= index) {
            // out of range
            return -1;
        }
        auto cur = head->next; // real head
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        // insert at head->next;
        auto node = new Node(val);
        head->next->prev = node;
        node->prev = head;
        node->next = head->next;
        head->next = node;
        len++;
    }

    void addAtTail(int val) {
        // insert at tail
        auto node = new Node(val);
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index > len) {
            // out of range
            return;
        }
        if (index == len) {
            // insert at tail
            addAtTail(val);
            return;
        }
        auto cur = head; // dummy head
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        auto node = new Node(val);
        cur->next->prev = node;
        node->prev = cur;
        node->next = cur->next;
        cur->next = node;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index >= len) {
            // out of range
            return;
        }
        auto cur = head; // dummy head
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        auto node = cur->next;
        cur->next = node->next;
        node->next->prev = cur;
        delete node;
        len--;
    }

  private:
    Node *head;
    Node *tail;
    int len;
};

int main() {
    MyLinkedList *obj = new MyLinkedList();
    int param_1 = obj->get(1);
    cout << param_1 << endl;
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    obj->deleteAtIndex(1);
    return 0;
}