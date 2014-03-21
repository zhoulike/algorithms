#include "linkedlist.h"

ListNode *detectCycle(ListNode *head) 
{
    ListNode *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    
    if (!fast || !fast->next)
        return NULL;
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
