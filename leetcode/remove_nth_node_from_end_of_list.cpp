/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        map<int, ListNode*> m;
        ListNode *prev, *tmp = head;
        
        if(!head)
            return NULL;
        
        int i = 1;
        while(tmp){
            m[i++] = tmp;
            tmp = tmp->next;
        }
        
        if(i - n - 1 == 0)
            return head->next;
        
        prev = m[i - n - 1];
        prev->next = prev->next->next;
        return head;
    }
};