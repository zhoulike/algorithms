/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> tmp_a(A, A+m);
        int i = 0,j = 0,k = 0;
        
        while(i < m && j < n)
            if(tmp_a[i] < B[j])
                A[k++] = tmp_a[i++];
            else
                A[k++] = B[j++];
        
        while(i < m)
            A[k++] = tmp_a[i++];
        while(j < n)
            A[k++] = B[j++];
    }

    void merge2(int A[], int m, int B[], int n) {
        int k = m + n;
        
        while(m > 0 && n > 0)
            if(A[m - 1] > B[n - 1])
                A[--k] = A[--m];
            else
                A[--k] = B[--n];
        
        while(n > 0)
            A[--k] = B[--n];
    }
};