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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1 || head == NULL)
            return head;
        
        int len = 0;
        for (ListNode *tmp = head; tmp; tmp = tmp->next)
            ++len;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        for (int i = 0; i < len / k; ++i) { 
            ListNode *p1, *p2;
            p1 = NULL;
            p2 = prev->next;
            for (int j = 0; j < k; ++j) {  //reverse a k-group
                ListNode *p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }
            
            //adjust the head and tail of the k-group
            ListNode *p_tail = prev->next;
            prev->next = p1;
            prev = p_tail;
            p_tail->next = p2;
        }
        
        return dummy.next;
    }
};
