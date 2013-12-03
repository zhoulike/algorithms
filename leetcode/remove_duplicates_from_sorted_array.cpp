/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1)
            return n;
        
        int i, j, tmp;
        i = j = 1;
        tmp = A[0];
        while(true){
            while(j < n && A[j] == tmp)
                ++j;
            if(j >= n)
                break;
                
            A[i] = A[j];
            tmp = A[j];
            ++i;
        }
        
        return i;
    }
};