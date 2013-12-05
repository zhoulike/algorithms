/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<vector<int> >::size_type i;
        vector<int>::size_type j;
        bool row_0 = false, column_0 = false;
        
        //row 0, column 0 have 0?
        for(i = 0; i < matrix.size(); ++i)
            if(matrix[i][0] == 0)
                column_0 = true;
        
        for(j = 0; j < matrix[0].size(); ++j)
            if(matrix[0][j] == 0)
                row_0 = true;
        
        //find 0 in other rows and columns
        for(i = 1; i < matrix.size(); ++i)
            for(j = 1;j < matrix[i].size(); ++j)
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        
        //set all the numbers in a row or a column to 0
        for(i = 1; i < matrix.size(); ++i)
            if(matrix[i][0] == 0)
                for(j = 1; j < matrix[i].size(); ++j)
                    matrix[i][j] = 0;
        
        for(j = 1; j < matrix[0].size(); ++j)
            if(matrix[0][j] == 0)
                for(i = 0; i < matrix.size(); ++i)
                    matrix[i][j] = 0;
        
        //set all the number in row 0 and column 0 to 0
        if(row_0 == true)
            for(j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        
        if(column_0 == true)
            for(i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
    }
};