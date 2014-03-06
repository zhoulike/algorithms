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
        return mergeSort(head);
    }

private:
    ListNode *mergeSort(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *right = slow->next;  //slow is the middle node
        slow->next = NULL;
        
        head = mergeSort(head);
        right = mergeSort(right);
        
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
