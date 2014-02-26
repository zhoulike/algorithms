class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
	    m['X'] = 10;
	    m['L'] = 50;
	    m['C'] = 100;
	    m['D'] = 500;
	    m['M'] = 1000;

	    int value = 0, tmp = 0;
	    for(auto c:s){
		    value += m[c];	
		    if(tmp < m[c])
			    value -= tmp * 2;
		    tmp = m[c];
	    }
	    return value;
    }
};