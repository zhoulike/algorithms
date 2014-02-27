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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1 || !l2)
            return l1? l1: l2;
        
        ListNode *p, *q, *tmp, *head = NULL;
        int carry = 0;

        for(p = l1, q = l2; p && q; p = p->next, q = q->next) {
        	if(!head) 
        		head = tmp = new ListNode((p->val + q->val + carry) % 10);
        	else {
        		tmp->next = new ListNode((p->val + q->val + carry) % 10);
        		tmp = tmp->next;
        	}
        	carry = (p->val + q->val + carry) / 10;
        }

        while(p) {
        	tmp->next = new ListNode((p->val + carry) % 10);
        	tmp = tmp->next;
        	carry = (p->val + carry) / 10;
        	p = p->next;
        }
        while(q) {
        	tmp->next = new ListNode((q->val + carry) % 10);
        	tmp = tmp->next;
        	carry = (q->val + carry) / 10;
        	q = q->next;
        }

        if(carry)
        	tmp->next = new ListNode(carry);

        return head;
    }
};