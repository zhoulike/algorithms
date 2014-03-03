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
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return NULL;
            
        ListNode *tmp = head->next;
        ListNode sorted(0);
        sorted.next = head;
        head->next = NULL;
        
        while(tmp){
            ListNode *p = &sorted, *q = tmp->next;
            for (; p->next != NULL && p->next->val < tmp->val; p = p->next)
                ;
                
            tmp->next = p->next;
            p->next = tmp;
            tmp = q;
        }
        
        return sorted.next;
    }
};