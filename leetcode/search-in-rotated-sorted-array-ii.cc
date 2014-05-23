class Solution {
public:
    bool search(int A[], int n, int target) {
        return solve(A, 0, n - 1, target);
    }
private:
    bool solve(int A[], int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (A[mid] == target)
                return true;
            else if (A[mid] == A[low] && A[mid] == A[high]) //solve duplication
                return solve(A, low, mid - 1, target) ||
                       solve(A, mid + 1, high, target);
            else if (A[mid] > target) {
                if (target < A[low] && A[high] < A[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {
                if (target > A[high] && A[low] > A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};
