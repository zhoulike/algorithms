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
    void reorderList(ListNode *head) {
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *reverse = NULL, *p = slow->next;  //find the second half of list
        slow->next = NULL;

        while (p) {  //reverse the second half of list
            ListNode *tmp = p->next;
            p->next = reverse;
            reverse = p;
            p = tmp;
        }

        p = head;
        while (p && reverse) {  //concatenate
            ListNode *tmp1 = p->next, *tmp2 = reverse->next;
            p->next = reverse;
            reverse->next = tmp1;
            p = tmp1;
            reverse = tmp2;
        }

        return;
    }
};
