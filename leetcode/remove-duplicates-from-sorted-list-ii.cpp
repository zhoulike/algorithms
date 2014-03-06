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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode tmp_head(0);
        tmp_head.next = head;
        
        for (ListNode *prev = &tmp_head, *p = tmp_head.next; p != NULL;) {
            if (p->next && p->val == p->next->val) {
                int dup = p->val;
                while (p && p->val == dup) {
                    prev->next = p->next;
                    delete p;
                    p = prev->next;
                }
            } else {
                prev = prev->next;
                p = p->next;
            }
        }
        
        return tmp_head.next;
    }
};

