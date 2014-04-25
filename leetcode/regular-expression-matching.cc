class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p)
            return false;
        if (*s == '\0' && *p == '\0')
            return true;
        if (*p != '\0' && p[1] == '*')
            return matchStar(s, p + 2, p[0]);
        if (*s != '\0' && *p != '\0' && (*s == *p || *p == '.'))
            return isMatch(s + 1, p + 1);
        return false;
    }
private:
    bool matchStar(const char *s, const char *p, char c) {
        do {
            if (isMatch(s, p))
                return true;
        } while (*s != '\0' && (*s++ == c || c == '.'));
        return false;
    }
};
