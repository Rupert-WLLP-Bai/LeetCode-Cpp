#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

void printList(ListNode *head);
ListNode *createList(const std::vector<int> &arr);