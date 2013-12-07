/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        auto iter = s.begin();

	    for(; iter != s.end(); ++iter)
		    if(*iter == '(' || *iter == '[' || *iter == '{')
			    st.push(*iter);
		    else if(!st.empty() && ((*iter == ')' && st.top() == '(') || (*iter == ']' && st.top() == '[') || (*iter == '}' && st.top() == '{')))
				    st.pop();
		    else
			    break;
	
	    return st.empty() && iter == s.end();
    }
};