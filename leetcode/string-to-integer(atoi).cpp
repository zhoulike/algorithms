class Solution {
public:
    int atoi(const char *str) {
    	if (!str)
    		return 0;

    	while (*str != '\0' && *str == ' ')  //skip spaces
    		++str;

    	int sign = 1;
    	if (*str == '+' || *str == '-') { //set correct sign, don't forget '+'
    		sign = *str == '+'? 1: -1;
    		++str;
    	}

    	double result = 0;  //integer may overflow
    	while (*str != '\0' && isdigit(*str)) {  //stop it when the character isn't a digit
    		result = result * 10 + *str - '0';
    		++str;
    	}

    	result *= sign;
    	if (result > INT_MAX)  //adjust value if overflow
    		result = INT_MAX;
    	if (result < INT_MIN)
    		result = INT_MIN;

    	return result;
    }
};