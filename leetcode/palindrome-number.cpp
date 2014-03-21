class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int mod = 1, tmp = x;
        while (tmp / 10) {
            mod *= 10;
            tmp /= 10;
        }
        
        while (x) {
            if (x / mod != x % 10)
                return false;
            x = (x % mod) /10;  //cut head & tail
            mod /= 100;
        }
        
        return true;
    }
};