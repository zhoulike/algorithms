/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *new_head = new ListNode(0);
        ListNode *tmp, *first, *second;
        
        new_head->next = head;
        tmp = new_head;
        
        while(tmp && tmp->next && tmp->next->next){
            first = tmp->next;
            second = tmp->next->next;
            
            first->next = second->next;
            second->next = first;
            tmp->next = second;
            tmp = first;
        }
        
        return new_head->next;
    }
};