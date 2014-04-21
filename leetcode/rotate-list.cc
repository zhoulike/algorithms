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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || !head)
            return head;
            
        int count = 1;
        ListNode *p = head;
        while (p->next) {   //count
            p = p->next;
            ++count;
        }
        p->next = head;  //link the list as a cycle
        
        p = head;
        for (int i = 1; i < count - k % count; ++i)  //rotate the right kth node. find the prev
            p = p->next;
            
        head = p->next; 
        p->next = NULL; //break the cycle
        return head;
    }
};
