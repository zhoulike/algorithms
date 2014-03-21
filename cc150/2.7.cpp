#include <iostream>
#include <stack>
#include "linkedlist.h"

using namespace std;

bool isPalindrome(ListNode *h1)
{
    ListNode *h2 = reverseList(copyList(h1)); //don't forget copy

    while (h1 && h2) { //actually, comparing a half of list is OK!
        if (h1->val != h2->val)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }

    destroyList(h2);
    return true;
}

bool isPalindrome2(ListNode *head)
{
    stack<int> stk;
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        stk.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    /*
     *fast, slow pointer:
     *1) if fast != NULL && fast->next == NULL, the list has odd nodes.
     *   slow is the middle node.
     *2) if fast == NULL, the list has even nodes.
     *   slow is the last of the two middle nodes.
     */

    if (fast) //if odd, the middle node is not pushed into the stack. Skip
        slow = slow->next;
    
    while (slow) {
        if (stk.top() != slow->val)
            return false;
        stk.pop();
        slow = slow->next;
    }

    return true;
}

int main(int argc, char *argv[])
{
    int a[5] = {1, 2, 3, 2, 1},
        b[5] = {1, 1, 2, 2, 1},
        c[4] = {1, 2, 2, 1};

    ListNode *pa = createList(a, 5),
             *pb = createList(b, 5),
             *pc = createList(c, 4);

    cout << isPalindrome2(pa) << endl;
    cout << isPalindrome2(pb) << endl;
    cout << isPalindrome2(pc) << endl;
    cout << isPalindrome2(NULL) << endl;

    destroyList(pa);
    destroyList(pb);
    destroyList(pc);
    return 0;
}
