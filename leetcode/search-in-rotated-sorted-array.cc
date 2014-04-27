class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (A[mid] == target)
                return mid;
            else if (A[mid] > target) {
                if (target < A[low] && A[high] < A[mid]) //must use A[mid]
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {
                if (target > A[high] && A[low] > A[mid]) //must use A[mid]
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};
