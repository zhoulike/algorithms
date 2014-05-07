class Solution {
public:
    string countAndSay(int n) {
        string s("1");

        while (--n) {
            string tmp;
            char ch = s.front();
            auto lower = s.begin();
            auto upper = s.begin();

            for (; upper != s.end(); ++upper) {
                if (*upper != ch) {
                    tmp += itoa(upper - lower);
                    tmp.push_back(ch);
                    lower = upper;
                    ch = *upper;
                }
            }

            tmp += itoa(upper - lower);
            tmp.push_back(ch);
            s = tmp;
        }

        return s;
    }
private:
    string itoa(int num) {
        stringstream sstrm;
        sstrm << num;
        return sstrm.str();
    }
};
