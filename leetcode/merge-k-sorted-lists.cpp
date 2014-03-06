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
    ListNode *mergeKLists(vector<ListNode *> &lists) {  //O(n * n)
        ListNode *head = NULL;
        
        for (int i = 0; i < lists.size(); ++i) 
            head = merge(head, lists[i]);
        
        return head;
    }
private:
    ListNode *merge(ListNode *p, ListNode *q) {
        ListNode dummy(0);
        ListNode *tmp = &dummy;
        
        while (p && q) {
            if (p->val < q->val) {
                tmp->next = p;
                p = p->next;
            } else {
                tmp->next = q;
                q = q->next;
            }
            tmp = tmp->next;
        }
        
        if (p)
            tmp->next = p;
        else
            tmp->next = q;
        
        return dummy.next;
    }
};