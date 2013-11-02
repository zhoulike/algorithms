#ifndef _BS_TREE_H
#define _BS_TREE_H

typedef int TYPE;

struct bs_root
{
	struct bs_node *rnode; 
};

struct bs_node 
{
	TYPE data;
	struct bs_node *parent;
	struct bs_node *left;
	struct bs_node *right;
};

struct bs_root* bs_root_init();
struct bs_node* bs_node_init(TYPE value);

struct bs_node* bs_minimum(struct bs_node* node);
struct bs_node* bs_maximum(struct bs_node* node);
struct bs_node* bs_predecessor(struct bs_node* node);
struct bs_node* bs_successor(struct bs_node* node);
struct bs_node* bs_search(struct bs_root* root, TYPE vaule);
int bs_insert(struct bs_root* root, struct bs_node* node);
void bs_delete(struct bs_root* root, struct bs_node* node);

#endif
