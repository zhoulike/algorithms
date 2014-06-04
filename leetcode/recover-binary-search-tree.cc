/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//time: O(n), space: O(n) stack
class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> vec;
        TreeNode *predecessor = nullptr;
        
        recoverInOrder(root, predecessor, vec);
        if (vec.size() > 0)
            swap(vec.front()->val, vec.back()->val);
    }
private:
    void recoverInOrder(TreeNode *root, TreeNode* &predecessor, vector<TreeNode *> &vec) {
        if (!root)
            return;
        
        recoverInOrder(root->left, predecessor, vec);
        if (predecessor && predecessor->val > root->val) {
            vec.push_back(predecessor);
            vec.push_back(root);
        }
        predecessor = root;
        recoverInOrder(root->right, predecessor, vec);
    }
};

//time: O(n), space: O(1)
class Solution {
public:
    void recoverTree(TreeNode *root) {
        recoverMorris(root);
    }
private:
    void recoverMorris(TreeNode *root) {
        if (!root)
            return;
            
        TreeNode *predecessor = nullptr, *current = root;
        vector<TreeNode *> vec;
        
        while (current) {
            if (!current->left) {
                if (predecessor && predecessor->val > current->val) {
                    vec.push_back(predecessor);
                    vec.push_back(current);
                }
                predecessor = current;
                current = current->right;
            } else {
                TreeNode *pre = current->left;  //find the predecssor of current node
                while (pre->right != nullptr && pre->right != current)
                    pre = pre->right;
                
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;  //recover the tree
                    if (predecessor && predecessor->val > current->val) {
                        vec.push_back(predecessor);
                        vec.push_back(current);
                    }
                    predecessor = current;
                    current = current->right;
                }
            }
        }
        
        if (vec.size() > 0)
            swap(vec.front()->val, vec.back()->val);
    }
};
