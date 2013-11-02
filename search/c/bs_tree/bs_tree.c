#include "bs_tree.h"
#include <stdlib.h>
#include <stdio.h>

struct bs_root* bs_root_init()
{
	struct bs_root *temp = NULL;
	if((temp = (struct bs_root*)malloc(sizeof(struct bs_root))) == NULL)
		return NULL;

	temp->rnode = NULL;

	return temp;
}

struct bs_node* bs_node_init(TYPE value)
{
	struct bs_node *temp = NULL;
	if((temp = (struct bs_node*)malloc(sizeof(struct bs_node))) == NULL)
		return NULL;

	temp->data = value;
	temp->parent = temp->left = temp->right = NULL;

	return temp;
}

/*return the node with minimum value of a tree or sub-tree*/
struct bs_node* bs_minimum(struct bs_node* node)
{
	if(node == NULL)
		return NULL;

	while(node->left)
		node = node->left;

	return node;
}

/*return the node with maximum value of a tree or sub-tree*/
struct bs_node* bs_maximum(struct bs_node* node)
{
	if(node == NULL)
		return NULL;

	while(node->right)
		node = node->right;

	return node;
}

struct bs_node* bs_predecessor(struct bs_node* node)
{
	if(node->left)
		return bs_maximum(node->left);

	struct bs_node* temp = node->parent;
	while(temp && node == temp->left) {
		node = temp;
		temp = node->parent;
	}

	return temp;
}

struct bs_node* bs_successor(struct bs_node* node)
{
	if(node->right)
		return bs_minimum(node->right);

	struct bs_node* temp = node->parent;
	while(temp && node == temp->right) {
		node = temp;
		temp = node->parent;
	}

	return temp;
}

struct bs_node* bs_search(struct bs_root* root, TYPE value)
{
	struct bs_node *root_node = root->rnode;

	while(root_node && root_node->data != value) {
		if(value < root_node->data)
			root_node = root_node->left;
		else
			root_node = root_node->right;
	}

	return root_node;
}

int bs_insert(struct bs_root* root, struct bs_node *node)
{
	if(!node) {
		printf("Insert a node with NULL pointer!\n");
		return -1;
	}
	
	if(!(root->rnode)){
		root->rnode = node;
		return 0;
	}
	
	struct bs_node *tmp,*parent;
	tmp = root->rnode;
	while(tmp){
		parent = tmp;
		if(node->data < parent->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	};
	
	if(node->data < parent->data){
		parent->left = node;
		node->parent = parent;
	}
	else{
		parent->right = node;
		node->parent = parent;
	}
	
	return 0;
}

void bs_delete(struct bs_root* root, struct bs_node* node)
{
	/*case 1: both childs is NULL*/
	if (!node->left && !node->right) {
		if(!node->parent)
			root->rnode = NULL;
		else{
			if(node == node->parent->left)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
		}
		free(node);
		return;
	}

	/*case 2: only one child is NULL*/
	if(!node->left){
		if(!node->parent){
			root->rnode = node->right;
			node->right->parent = NULL;
		}
		else{
			node->parent->right = node->right;
			node->right->parent = node->parent;	
		}
		free(node);
		return;
	}
	else if (!node->right) {
		if(!node->parent){
			root->rnode = node->left;
			node->left->parent = NULL;
		}
		else{
			node->parent->left = node->left;
			node->left->parent = node->parent;	
		}
		free(node);
		return;
	}
	else{
	/*case 3: both childs are not NULL*/
		struct bs_node* succ = bs_successor(node);
		node->data = succ->data;
		bs_delete(root, succ);
	}
}
