/*
Given a number represented as an array of digits, plus one to the number.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        vector<int> ivec;
        
        for(std::vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); ++iter){
            ivec.push_back((*iter + carry) % 10);
            carry = (*iter + carry) / 10;
        }
        
        if(carry > 0)
            ivec.push_back(carry);
        
        return vector<int>(ivec.rbegin(), ivec.rend());
    }
};