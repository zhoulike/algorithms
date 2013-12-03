/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1, mid;
        
        while(low <= high){
			//note: >> has lower precedence than +	
            mid = low + ((high - low) >> 1);
            
            if(A[mid] == target)
                return mid;
            else if(A[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
		return low;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 3};
    cout << s.searchInsert(a, 2, 2) << endl;
    return 0;
}
