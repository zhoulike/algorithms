class Solution {
public:
    int sqrt(int x) {
        if (x <= 0)   //don't forget 0
            return x;
            
        double val = x, prev;

        do {
            prev = val;
            val = (val + x / val) / 2;
        } while(abs(val - prev) > numeric_limits<double>::epsilon());

        return (int)val;
    }
};