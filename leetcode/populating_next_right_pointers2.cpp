/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *leftmost, *tmp1, *tmp2 = NULL;
        leftmost = root;
        
        while(leftmost){
            tmp1 = leftmost;
            tmp2 = leftmost = NULL;
            while(tmp1){
                if(tmp1->left){
                    if(!leftmost)
                        tmp2 = leftmost = tmp1->left;
                    else
                        tmp2 = tmp2->next = tmp1->left;
                }
                if(tmp1->right){
                    if(!leftmost) 
                        tmp2 = leftmost = tmp1->right;
                    else
                        tmp2 = tmp2->next = tmp1->right;
                }
                tmp1 = tmp1->next;
            }
        }
    }
};