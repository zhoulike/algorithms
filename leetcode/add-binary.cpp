class Solution {
public:
    string addBinary(string a, string b) {
        string r_a(a.rbegin(), a.rend()), r_b(b.rbegin(), b.rend());
        string ret;
        string::const_iterator iter_a, iter_b;
        int carry = 0, sum = 0;

        for(iter_a = r_a.begin(), iter_b = r_b.begin(); iter_a != r_a.end() && iter_b != r_b.end(); ++iter_a, ++iter_b) {
        	sum = carry + _atoi(*iter_a) + _atoi(*iter_b);
        	carry = sum / 2;
        	ret.push_back(_itoa(sum % 2));
        }

        while(iter_a != r_a.end()) {
        	sum = carry + _atoi(*iter_a);
        	carry = sum / 2;
        	ret.push_back(_itoa(sum % 2));
        	++iter_a;
        }
        while(iter_b != r_b.end()) {
        	sum = carry + _atoi(*iter_b);
        	carry = sum / 2;
        	ret.push_back(_itoa(sum % 2));
        	++iter_b;
        }

        if(carry)  //don't forget the last carry
        	ret.push_back(_itoa(carry));

        return string(ret.rbegin(), ret.rend());
    }
private:
	int _atoi(const char c) {
		return c - '0';
	}
	char _itoa(int i) {
		return i + '0';
	}
};