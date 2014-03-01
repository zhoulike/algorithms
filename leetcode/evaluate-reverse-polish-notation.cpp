class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	stack<int> stk;
        
        for (auto iter = tokens.begin(); iter != tokens.end(); ++iter) {
            string op = "+-*/";
        	int a, b;

            if (op.find(*iter) != -1) {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();

                if (*iter == "+")
                    stk.push(a + b);
                else if (*iter == "-")
                    stk.push(a - b);
                else if (*iter == "*")
                    stk.push(a * b);
                else
                    stk.push(a / b);
        	} else {
        		stk.push(atoi(iter->c_str()));
        	}
        }
        return stk.top();
    }
};