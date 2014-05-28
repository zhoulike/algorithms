class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3)
            return 0;

        int left = 0, right = n - 1, count = 0;
        int left_max = A[left], right_max = A[right];

        while (left < right) {
            if (A[left] < A[right]) {
                ++left;
                if (A[left] > left_max)
                    left_max = A[left];
                else
                    count += left_max - A[left];
            } else {
                --right;
                if (A[right] > right_max)
                    right_max = A[right];
                else
                    count += right_max - A[right];
            }
        }

        return count;
    }
};
