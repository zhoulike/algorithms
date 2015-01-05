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

//divide and conquer solution
class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divide_conquer(lists, 0, lists.size() - 1);
    }
private:
    ListNode *divide_conquer(vector<ListNode *> &lists, int low, int high) {
        if (low > high)
            return nullptr;
        else if (low == high)
            return lists[low];

        int mid = low + (high - low) / 2;
        ListNode *first = divide_conquer(lists, low, mid),
                 *second = divide_conquer(lists, mid + 1, high);

        ListNode ans(0);
        ListNode *prev = &ans;
        while (first && second) {
            if (first->val < second->val) {
                prev->next = first;
                first = first->next;
            } else {
                prev->next = second;
                second = second->next;
            }
            prev = prev->next;
        }
        if (first)
            prev->next = first; 
        if (second)
            prev->next = second;
        return ans.next;
    }
};
