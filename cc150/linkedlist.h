#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

ListNode* createList(int a[], int n)
{
    ListNode *head = NULL, *prev;
    for (int i = 0; i < n; ++i) {
        ListNode *node = new ListNode(a[i]);
        if (head == NULL) {
            head = node;
            prev = node;
        } else { 
            prev->next = node;
            prev = node;
        }
    }

    return head;
}

void displayList(ListNode *head)
{
    for (ListNode *tmp = head; tmp != NULL; tmp = tmp->next) {
        std::cout << tmp->val << " ";
    }

    std::cout << std::endl;
}

void destroyList(ListNode *head)
{
    for (ListNode *p = head; p; ) {
        ListNode *q = p->next;
        delete p;
        p = q;
    }
}

#endif
