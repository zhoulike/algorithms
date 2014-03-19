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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (n == m)
            return head;
            
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *p = &dummy, *first;   //first: the node before reversed part
        for (int i = 1; i < m; ++i)
            p = p->next;
        
        first = p;
        p = p->next;
        
        ListNode *prev = NULL, *r_end = p;  //r_end: the end of reversed part
        for (int i = m; i <= n; ++i) {
            if (!p)
                break;
                
            ListNode *q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        } //after the loop, prev is the first node of reversed part, p is the node after reversed part
        
        first->next = prev;
        r_end->next = p;
        
        return dummy.next;
    }
};