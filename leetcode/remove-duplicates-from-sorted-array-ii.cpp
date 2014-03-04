class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) //don't forget edge condition: n == 0
            return n;
            
    	int i = 0;
    	int dup_num = 1;   //current duplicated items in the array
        for (int j = 1; j < n; ++j) {
        	if (dup_num == 2 && A[i] == A[j])
        		continue;

			if (A[i] != A[j])
				dup_num = 1;
			else
				++dup_num;
        	A[++i] = A[j]; 				
        }

        return i + 1;
    }
};