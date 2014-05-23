class Solution {
public:
    double pow(double x, int n) {
        if (n == 1)
            return x;
        else if (n == 0)
            return 1;
        else if (n < 0) {
            if (n > INT_MIN)
                return 1 / pow(x, -n);
            else 
                return 1 / (pow(x, -(n + 1)) * x);  //n = -2147483648
        }
            
        double half = pow(x, n / 2);
        return half * half * pow(x, n - n / 2 - n / 2);
    }
};
