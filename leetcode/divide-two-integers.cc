class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        else if(divisor == 0)
            throw overflow_error("Divided by zero!");
        
        unsigned int u_dividend = dividend > 0? dividend: (dividend == INT_MIN? (INT_MAX + 1): -dividend), 
                     u_divisor = divisor > 0? divisor: (divisor == INT_MIN? (INT_MAX + 1): -divisor);

        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;

        unsigned n = divide(u_dividend, u_divisor);
        return sign < 0? (0 - n): n;
    }
private:
    unsigned divide(unsigned dividend, unsigned divisor)
    {
        if (divisor > dividend)
            return 0;
        else if (divisor == dividend)
            return 1;
        else if (divisor == 1)
            return dividend;
        else if (divisor == 2)
            return dividend >> 1;

        unsigned ans = 0, count = 1, new_divisor = divisor;
        while (new_divisor + new_divisor <= dividend) {
            count <<= 1;
            new_divisor <<= 1;
        }
        ans = count + divide(dividend - new_divisor, divisor);
        return ans;
    }
};
