class Solution {
public:
    void sortColors(int A[], int n) {
	    int i,j,k;
	    
	    for(i = -1; A[i + 1] == 0; ++i)
		    ;
	    j = i + 1;
	    for(k = n; A[k - 1] == 2; --k)
		    ;

	    while(j < k)
		    if(A[j] == 0)
			    swap(A[++i], A[j++]);
		    else if(A[j] == 2)
			    swap(A[j], A[--k]);
		    else
		    	++j;
    }
};