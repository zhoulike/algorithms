class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	if (triangle.size() == 0)
    		return 0;

        vector<int> v(triangle.size());
        v[0] = (triangle[0][0]);

        for (int i = 1; i < triangle.size(); ++i) {
        	vector<int> tmp(v);
        	v[0] = tmp[0] + triangle[i][0];  //first element, no left adjacent

        	for (int j = 1; j < triangle[i].size(); ++j) { 
        		v[j] = tmp[j - 1] + triangle[i][j];  //left adjacent
        		if (j < triangle[i].size() - 1 && tmp[j] + triangle[i][j] < v[j]) //last element, no right adjacent
        			v[j] = triangle[i][j] + tmp[j]; //right adjacent
        	}
        }

        int minimum = v[0];
        for (int i = 1; i < v.size(); ++i)
        	minimum = min(minimum, v[i]);

        return minimum;
    }
};