/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }

        int prev = 0, curr = 0;
        while (x) {
            curr = prev * 10 + x % 10;
            if (curr < prev) //check overflow
                return 0;
            prev = curr;
            x /= 10;
        }
        return curr * sign;
    }
};
