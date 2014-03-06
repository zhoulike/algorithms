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
    ListNode *sortList(ListNode *head) {
        int count = 0;
        for (ListNode *tmp = head; tmp != NULL; tmp = tmp->next) 
            ++count;
            
        return mergeSort(head, count);
    }

private:
    ListNode *mergeSort(ListNode *head, int n) {
        if (n <= 1)
            return head;
        
        ListNode *tmp = head;
        for (int i = 1; i < n / 2; ++i)
            tmp = tmp->next;
        
        ListNode *right = tmp->next;
        tmp->next = NULL;
        
        head = mergeSort(head, n / 2);
        right = mergeSort(right, n - n / 2);
        
        return merge(head, right);
    }
    
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode tmp_head(0);
        ListNode *tmp = &tmp_head;
        
        while (left && right) {
            if (left->val < right->val) {
                tmp->next = left;
                left = left->next;
            } else {
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        
        if (left)
            tmp->next = left;
        else
            tmp->next = right;
        
        return tmp_head.next;
    }
};
