#include <iostream>
#include "linkedlist.h"

using namespace std;

ListNode* backwardAdd(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;

    int carry = 0;
    ListNode *head = NULL, *prev = NULL;

    ListNode *p, *q;
    for (p = l1, q = l2; p && q; p = p->next, q = q->next) {
        int sum = p->val + q->val + carry;
        if (!head) {
            head = new ListNode(sum % 10);
            prev = head;
        } else {
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
        }
        carry = sum / 10;
    }

    while (p) {
        if (!head) {
            head = new ListNode((p->val + carry) % 10);
            prev = head;
        } else {
            prev->next = new ListNode((p->val + carry) % 10);
            prev = prev->next;
        }
        carry = (p->val + carry) / 10;
        p = p->next;
    }

    while (q) {
        if (!head) {
            head = new ListNode((q->val + carry) % 10);
            prev = head;
        } else {
            prev->next = new ListNode((q->val + carry) % 10);
            prev = prev->next;
        }
        carry = (q->val + carry) / 10;
        q = q->next;
    }

    if (carry)  //don't forget the last carry
        prev->next = new ListNode(carry);

    return head;
}

ListNode* forwardAdd(ListNode *l1, ListNode *l2)
{
    return reverseList(backwardAdd(reverseList(l1), reverseList(l2)));
}


int main(int argc, char *argv[])
{
    int a[1] = {1},
        b[3] = {9, 9, 9};

    ListNode *pa = createList(a, 1),
             *pb = createList(b, 3);

    ListNode *result = backwardAdd(pa, pb);
    displayList(result);

    ListNode *result2 = forwardAdd(pa, pb);
    displayList(result2);

    destroyList(pa);
    destroyList(pb);
    destroyList(result);
    destroyList(result2);

    return 0;
}
