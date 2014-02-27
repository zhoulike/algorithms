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
    ListNode *partition(ListNode *head, int x) {
        ListNode *s_head, *l_head, *s_tmp, *l_tmp;
        s_head = l_head = NULL;
        
        while(head){
            if(head->val < x) {
                if(s_head == NULL)
                    s_head = s_tmp = head;
                else {
                    s_tmp->next = head;
                    s_tmp = s_tmp->next;
                }
            } else {
                if(l_head == NULL)
                    l_head = l_tmp = head;
                else {
                    l_tmp->next = head;
                    l_tmp = l_tmp->next;
                }
            }
            head = head->next;
        }
        
        if(s_head) {
            s_tmp->next = l_head;
            l_tmp->next = NULL;   //Don't forget this line. Otherwise, it may cause a loop in the new list.
        }
        else
            s_head = l_head;
            
        return s_head;
    }
};