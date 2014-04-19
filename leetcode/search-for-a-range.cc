class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans = {-1, -1};
        if (n <= 0)
            return ans;

        int left, right, tmp;
        left = right = binary_search(A, 0, n - 1, target);

        while ((tmp = binary_search(A, 0, left - 1, target)) != -1)
            left = tmp;

        while ((tmp = binary_search(A, right + 1, n - 1, target)) != -1)
            right = tmp;

        ans[0] = left;
        ans[1] = right;

        return ans;
    }
private:
    int binary_search(int A[], int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
