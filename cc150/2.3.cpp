#include <iostream>
#include "linkedlist.h"

using namespace std;

void deleteNode(ListNode *node)
{
    if (!node || !node->next)  //cannot delete the last node
        return;

    ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    delete p;
}

int main(int argc, char *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    ListNode *pa = createList(a, 5);

    deleteNode(pa->next->next);
    displayList(pa);
    deleteNode(pa->next);
    displayList(pa);
    deleteNode(pa);
    displayList(pa);

    destroyList(pa);
    return 0;
}
