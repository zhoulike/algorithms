/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
        int flag, result = 0;
        
        if(x < 0){
            flag = -1;
            x *= flag;
        } else
            flag = 1;
        
        while(x){
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        return result * flag;
    }
};