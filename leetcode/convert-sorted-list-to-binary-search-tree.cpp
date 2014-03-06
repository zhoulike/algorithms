/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> vlist;
        for (ListNode *tmp = head; tmp != NULL; tmp = tmp->next)
            vlist.push_back(tmp->val);
        return sortedArrayToBST(vlist);  //uses 'Convert Sorted Array to Binary Search Tree'
    }
private:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return child(num.begin(), num.end());
    }
    TreeNode *child(vector<int>::iterator first, vector<int>::iterator last)
    {
        if (first >= last)
            return NULL;
        
        vector<int>::iterator mid = first + (last - first) / 2;
        TreeNode *p = new TreeNode(*mid);
            
        p->left = child(first, mid);  //note: [first, last)
        p->right = child(mid + 1, last);
        
        return p;
    }
};