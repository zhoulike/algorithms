/*题目描述：
  给你一个数组A[1..n]，请你在O(n)的时间里构造一个新的数组B[1..n]，使得B[i]=A[1]*A[2]*...*A[n]/A[i]。你不能使用除法运算。
*/

#include <stdio.h>
#include <stdlib.h>

void forget_product(int a[], int b[], int size)
{
/*space: O(n)*/
	if (size <= 0)
		return;
	
	/*
 	 * left[i] = a[0] * a[1] ... * a[i - 1]
	 * right[i] = a[i + 1] * a[i + 2] * ... * a[n - 1]
	 */
	int *left, *right;
	left = (int*)malloc(sizeof(int) * size);	
	right = (int*)malloc(sizeof(int) * size);	
	if (!left || !right) {
		printf("out of memory!\n");
		return;
	}

	int i;
	left[0] = 1;
	for (i = 1; i < size; ++i)
		left[i] = left[i - 1] * a[i - 1];

	right[size - 1] = 1;
	for (i = size - 2; i >= 0; --i)
		right[i] = right[i + 1] * a[i + 1];

	for (i = 0; i < size; ++i)
		b[i] = left[i] * right[i];
}

void forget_product_opt(int a[], int b[], int size)
{
/*space: O(1)*/
	if (size <= 0)
		return;
	
	int right;
	
	int i;
	b[0] = 1, right = a[size - 1];
	for (i = 1; i < size; ++i)
		b[i] = b[i - 1] * a[i - 1];

	for (i = size - 2; i >= 0; --i) {
		b[i] = b[i] * right;
		right *= a[i];
	}
}

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3, 4, 5};
	int b[5], i, c[5];
	
	forget_product(a, b, sizeof(a) / sizeof(a[0]));
	forget_product_opt(a, c, sizeof(a) / sizeof(a[0]));
	for (i = 0; i < 5; ++i)
		printf("%d %d\n", b[i], c[i]);

	return 0;
}
