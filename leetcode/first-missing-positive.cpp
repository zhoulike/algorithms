class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n <= 0)
            return 1;  //first postive = 1

    	int i = 0;
        while (i < n) {
        	if (A[i] != i && A[i] >= 0 && A[i] < n && A[A[i]] != A[i])  //put A[i] to proper position
        		swap(A[A[i]], A[i]);
        	else
        		++i;
        }

        for (i = 1; i < n && A[i] == i; ++i)
        	;
        return A[0] == i? i + 1: i;   //mention this case: a[] = {1, 2, 3}  -> {3, 1, 2};
    }
};