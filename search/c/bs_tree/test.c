#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"

void initalize(struct bs_root **root, TYPE a[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		struct bs_node *node = bs_node_init(a[i]);
		if(!node){
			printf("out of memory!\n");
			return;	
		}
		bs_insert(*root, node);
	}
}

void test(struct bs_root *root, TYPE value)
{
	if(bs_search(root, value))
		printf("find %d!\n", value);
	else
		printf("cannot find %d!\n",value);
}

void test_remove(struct bs_root *root, TYPE a[], int size)
{
	struct bs_node *node;
	int i = 4;

	for (i = 4; i < size; ++i)
	{
		node = bs_search(root, a[i]);
		printf("remove %d!\n", node->data);
		bs_delete(root, node);
	}
	for (i = 0; i < 4; ++i)
	{
		node = bs_search(root, a[i]);
		printf("remove %d!\n", node->data);
		bs_delete(root, node);
	}
	if(!(root->rnode))
		printf("Now, it's an empty tree!\n");
}

int main()
{
	struct bs_root *root = bs_root_init();
	TYPE a[9] = {12, 5, 2, 9, 18, 15, 13, 17, 19};

	initalize(&root, a, 9);
	test(root, 1);
	test(root, 22);
	test(root, a[3]);
	test(root, a[8]);
	test(root, a[0]);
	test_remove(root, a, 9);
	
	return 0;
}
