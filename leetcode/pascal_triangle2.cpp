/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ivec;

	    ivec.push_back(1);
	    while(rowIndex--){
		    auto iter = ivec.begin();
		    int tmp1 = *iter, tmp2;

		    while(++iter != ivec.end()){
			    tmp2 = *iter;
			    *iter = tmp1 + tmp2;
			    tmp1 = tmp2;
	    	}
		    ivec.insert(iter, 1);
	    }

	    return ivec;
    }
};