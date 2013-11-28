/*题目描述：
给定一个无序的整数数组，怎么找到第一个大于0，并且不在此数组的最小整数。比如[1,2,0] 返回 3, [3,4,-1,1] 返回 2。最好能O(1)空间和O(n)时间。
*/

#include <stdio.h>

int least_above0(int a[], int size)
{
	int i;

	for(i = 0; i < size;)
	{
		/*Warning: a[i] > size is wrong, such as [1,2,3,4,5], a[5] is not legal*/
		if (a[i] == i || a[a[i]] == a[i] || a[i] < 0 || a[i] >= size)
			++i;
		else {
			int tmp;
			tmp = a[a[i]];
			a[a[i]] = a[i];
			a[i] = tmp;
		}	
	}

	for (i = 1; i < size; ++i)
	{
		if (a[i] != i) {
			return i;
		}
	}

	/*Warning: return i is wrong, such as [1,2,3,4,5]. return i will return 5*/
	return i + (a[0] == size);
}

void test(int a[], int size, int number)
{
	if (least_above0(a, size) == number) {
		printf("test passed!\n");
	} else {
		printf("test failed!\n");
	}
}

int main(int argc, char *argv[])
{
	int a[] = {-1, 0 , 2, 3},
		b[] = {0, 2, 2, 1, 3, 5},
		c[] = {3, 2, 2, 1, 0},
		d[] = {3, 0, 1, 2, 55},
		e[] = {1, 2, 0},
		f[] = {3, 4, -1, 1},
		g[] = {1, 2, 3, 4, 5};

	test(a, sizeof(a) / sizeof(a[0]), 1);	
	test(b, sizeof(b) / sizeof(b[0]), 4);	
	test(c, sizeof(c) / sizeof(c[0]), 4);	
	test(d, sizeof(d) / sizeof(d[0]), 4);	
	test(e, sizeof(e) / sizeof(e[0]), 3);	
	test(f, sizeof(f) / sizeof(f[0]), 2);	
	test(g, sizeof(g) / sizeof(g[0]), 6);	

	return 0;
}
