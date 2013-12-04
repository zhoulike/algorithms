/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::stack<TreeNode*> s;
        std::vector<int> ivec;
        int new_node = 1;
        
        if(root)
            s.push(root);
        
        while(!s.empty()){
            TreeNode *node = s.top();

            /*use new_node to avoid infinite loop. It is used to avoid to visit a node that has visited. e.g.
                1
               /
              2
              It causes infinite loop without new_node.
            */
            if(node->left && new_node)
                s.push(node->left);
            else{
                ivec.push_back(node->val);
                s.pop();
                new_node = 0;
                if(node->right){
                    s.push(node->right);
                    new_node = 1;
                }
            }
        }
        
        return ivec;
    }
};