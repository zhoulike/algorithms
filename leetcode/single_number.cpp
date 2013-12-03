/*description:
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <iostream>

using namespace std;

class Solution{
public:
	int singleNumber(int A[], int n){
		int result = 0;
		for (int i = 0; i < n; ++i)
			result ^= A[i];

		return result;
	}

	int singleNumber2(int A[], int n){
		if (n < 1) 
			return 0;
		while(--n >= 1)
			A[n - 1] ^= A[n];	
		return A[0];	
	}
};

int main(int argc, char *argv[])
{
	int a[5] = {0, 2, 1, 0, 2},
		b[7] = {1, 2, 3, 3, 2, 1, 0};

	Solution s;
	cout << s.singleNumber(a, 5) << endl << s.singleNumber(b, 7) << endl;
	cout << s.singleNumber2(a, 5) << endl << s.singleNumber2(b, 7) << endl;
	return 0;
}
