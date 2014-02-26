/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
            
        map<RandomListNode*, RandomListNode*> p_map;
        RandomListNode *new_list = new RandomListNode(head->label);
        RandomListNode *new_tmp = new_list;
        p_map[head] = new_tmp;
        
        for(RandomListNode *tmp = head->next; tmp != NULL; tmp = tmp->next){
            new_tmp->next = new RandomListNode(tmp->label);
            new_tmp = new_tmp->next;
            p_map[tmp] = new_tmp;
        }
        for(RandomListNode *tmp = head, *new_tmp = new_list; tmp != NULL; tmp = tmp->next, new_tmp = new_tmp->next)
            new_tmp->random = p_map[tmp->random];
        
        return new_list;
    }
};