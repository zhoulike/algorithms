class Solution {
public:
    int maxSubArray(int A[], int n) {
		if(n <= 0)
			return 0;

		int *sum = new int[n];
		int max = sum[0] = A[0];
		for (int i = 1; i < n; ++i) {
			sum[i] = A[i];
			if(A[i] + sum[i - 1] > sum[i])
				sum[i] = A[i] + sum[i - 1];
			if(sum[i] > max)
				max = sum[i];
		}
		
		delete sum;
		return max;        
    }
};