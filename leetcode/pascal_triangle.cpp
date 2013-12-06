/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > v(numRows);
        int i;
        
        if(numRows == 0)
            return v;
        
        v[0].push_back(1);
        for(i = 1; i < numRows; ++i){
            v[i].push_back(1);
            v[i].push_back(1);
        }
        
        for(i = 2; i < numRows; ++i){
            auto iter = v[i].end() - 1;
            for(auto j = v[i-1].size() - 1; j > 0; --j)
                iter = v[i].insert(iter, v[i-1][j] + v[i-1][j-1]);
        }
        
        return v;
    }
};