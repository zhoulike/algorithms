/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 0 || (n > 1 && A[0] == 0))
		    return false;

	    int pos0 = 0;
	    int last_pos = n - 1;
	    while(n--)
		    if(pos0 == 0 && A[n] == 0)
			    pos0 = n;
		    else if((pos0 && A[n] > pos0 - n) || (pos0 == last_pos && A[n] == pos0 - n))
			    pos0 = 0;
	
	    return pos0 == 0;
    }
};