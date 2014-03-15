#include <iostream>
#include "linkedlist.h"

using namespace std;

ListNode* partition(ListNode *head, int x)
{
    ListNode dummy(0);
    dummy.next = head;

    ListNode *large = NULL, *prev_l = NULL, *prev;
    prev = &dummy;

    for (ListNode *p = head; p; p = p->next) {
        if (p->val >= x) {
            if (!large) {
                large = p;
                prev_l = p;
            } else {
                prev_l->next = p;
                prev_l = prev_l->next;
            }
            prev->next = p->next; //delete p from orignal list
        } else {
            prev = prev->next;
        }
    }

    if (large) {
        prev_l->next = NULL;
        prev->next = large;
    }

    return dummy.next;
}


int main(int argc, char *argv[])
{
    int a[10] = {2, 3, 6, 7, 4, 1, 5, 8, 1, 1};

    ListNode *pa = createList(a, 10);

    displayList(pa);
    pa = partition(pa, 5);
    displayList(pa);
    pa = partition(pa, 10);
    displayList(pa);
    pa = partition(pa, 0);
    displayList(pa);
    pa = partition(pa, 2);
    displayList(pa);
    partition(NULL, 20);

    destroyList(pa);
    return 0;
}
