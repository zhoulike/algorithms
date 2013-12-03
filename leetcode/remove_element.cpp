/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = n, tmp;
        
        while(i < j){
            if(A[i] == elem){
                if(i == j - 1)
                    return i;
                
                tmp = A[i];
                A[i] = A[j - 1];
                A[j - 1] = tmp;
                --j;
            }
            if(A[i] != elem)
                ++i;
        }
        
        return i;
    }
};