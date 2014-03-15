#include <iostream>
#include "linkedlist.h"

using namespace std;

//O(n) time, O(1) space
int kthElement(ListNode *head, int k)
{
    if (!head || k <= 0)
        return -1;

    ListNode *p = head;
    int i;
    for (i = 0; i < k && p; ++i)
        p = p->next;

    if (i != k) //k is to large. cannot be if (!p)
        return -1;

    ListNode *q = head;
    while (p) {
        q = q->next;
        p = p->next;
    }

    return q->val;
}

int main(int argc, char *argv[])
{
    int a[1] = {1},
        b[5] = {1, 2, 3, 4, 5};

    ListNode *pa = createList(a, 1),
             *pb = createList(b, 5),
             *pnull = NULL;

    cout << kthElement(pnull, 5) << endl;
    cout << kthElement(pa, 5) << endl;
    cout << kthElement(pa, 1) << endl;
    cout << kthElement(pb, 5) << endl;
    cout << kthElement(pb, 3) << endl;
    cout << kthElement(pb, 1) << endl;

    destroyList(pa);
    destroyList(pb);
    destroyList(pnull);

    return 0;
}
