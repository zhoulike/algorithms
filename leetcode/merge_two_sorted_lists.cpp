/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *tmp = NULL, *rest = NULL;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                if(head == NULL)
                    head = tmp = l1;
                else
                    tmp = tmp->next = l1;
                l1 = l1->next;
            } else {
                if(head == NULL)
                    head = tmp = l2;
                else
                    tmp = tmp->next = l2;
                l2 = l2->next;
            }
        }
        
        rest = (l1 == NULL)? l2: l1;
        if(head == NULL)
            head = rest;
        else
            tmp->next = rest;
        
        return head;
    }
};