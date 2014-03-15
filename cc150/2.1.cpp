#include <iostream>
#include <map>
#include "linkedlist.h"

using namespace std;

//O(n*n) time, O(1) space
ListNode* removeDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;

    for (ListNode *p = head; p; p = p->next) {
        ListNode *prev = p;
        for (ListNode *q = p->next; q; ) {
            if (q->val == p->val) {
                prev->next = q->next;
                delete q;
                q = prev->next;
            } else {
                prev = prev->next;
                q = q->next;
            }
        }
    }

    return head;
}

//O(n) time, O(n) space
ListNode* removeDuplicates2(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *prev = head, *p = head->next;
    map<int, bool> m;
    m[head->val] = true;

    while (p) {
        if (m.find(p->val) == m.end()) {
            m[p->val] = true;
            prev = prev->next;
            p = p->next;
        } else {
            prev->next = p->next;
            delete p;
            p = prev->next;
        }
    }

    return head;
}

typedef ListNode* (*FUNC)(ListNode *head);

void test(FUNC f)
{
    int a[1] = {1},
        b[5] = {1, 2, 1, 2, 1},
        c[5] = {1, 1, 1, 1, 1},
        d[10] = {1, 1, 2, 2, 3, 1, 2, 1, 2, 3};

    ListNode *pnull = f(NULL),
             *pa = f(createList(a, 1)),
             *pb = f(createList(b, 5)),
             *pc = f(createList(c, 5)),
             *pd = f(createList(d, 10));

    displayList(pnull);
    displayList(pa);
    displayList(pb);
    displayList(pc);
    displayList(pd);

    destroyList(pnull);
    destroyList(pa);
    destroyList(pb);
    destroyList(pc);
    destroyList(pd);
}

int main(int argc, char *argv[])
{
    test(removeDuplicates);
    test(removeDuplicates2);
    return 0;
}
