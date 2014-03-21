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

ListNode *copyList(ListNode *head)
{
    ListNode *copy = NULL, *prev;
    while (head) {
        if (!copy) {
            copy = new ListNode(head->val);
            prev = copy;
        } else {
            prev->next = new ListNode(head->val);
            prev = prev->next;
        }
        head = head->next;
    }

    return copy;
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

ListNode* reverseList(ListNode *head)
{
    ListNode *prev = NULL, *p = head;
    while (p) {
        ListNode *q = p->next;
        p->next = prev;
        prev = p;
        if (q == NULL) 
            head = p;
        p = q;
    }

    return head;
}

#endif
