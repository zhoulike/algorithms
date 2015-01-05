class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0)
            return 0;
        int max_sum = A[0], curr_sum = A[0];
        for (int i = 1; i < n; ++i) {
            curr_sum = max(curr_sum + A[i], A[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
