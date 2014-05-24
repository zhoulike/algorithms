class Solution {
public:
    int jump(int A[], int n) {
        vector<int> steps(n, 0);
        int prev = 0;
        
        for (int i = 1; i < n;) {
            if (i - prev <= A[prev]) { //prev pos can reach here
                steps[i] = steps[prev] + 1;
                ++i;
            } else  //previous pos cannot reach here, increase previous pos
                ++prev;
        }

        return steps.back();
    }
};
