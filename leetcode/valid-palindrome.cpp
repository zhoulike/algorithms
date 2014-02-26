class Solution {
public:
    bool isPalindrome(string s) {
		if (s.length() == 0) {
			return true;
		}

		string::iterator first = s.begin(), last = s.end() - 1;
		while(first < last) {
			while(first < last && !isalnum(*first))
				++first;
			while(first < last && !isalnum(*last))
				--last;
			if(toupper(*first) != toupper(*last))
				break;
			else{
				++first;
				--last;
			}
			
		}
		return first >= last;
    }
};