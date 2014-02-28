class Solution {
public:
    string simplifyPath(string path) {
    	if(path.size() == 0)
    		return string("");

    	deque<string> q;
        string::iterator first, last;
        first = last = path.end();

        for (string::iterator iter = path.begin(); iter != path.end(); ++iter) {
        	if (*iter != '/') {
        		if (first == path.end())
        			first = iter;
        	}
        	else {
        		if (first == path.end())
        			continue;

        		last = iter;
        		process_string(q, string(first, last));	
        		first = last = path.end();  //avoid '//'	
        	} 
        }

        if (first != path.end())   // don't forget "/home"
        	process_string(q, string(first, path.end()));

        string ret;
        while (!q.empty()) {
        	ret += "/" + q.front();
        	q.pop_front();
        }

        return ret.size() == 0? "/": ret;
    }

private:
	void process_string(deque<string> &q, string s) {
		if (s == ".")
        	return;
        else if (s == "..") {
        	if (!q.empty())
        		q.pop_back();
        }
        else
        	q.push_back(s);
	}
};