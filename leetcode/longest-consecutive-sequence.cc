//Actually, this is O(nlogn) solution
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())
            return 0;
            
        set<int> s(num.begin(), num.end()); //red-black tree, O(nlogn)
        auto iter = s.begin();
        
        int first, last;
        int longest = 0;
        
        first = last = *iter;
        ++iter;
        for (; iter != s.end(); ++iter) {
            if (*iter != last + 1) {
                longest = max(longest, last - first + 1);
                last = first = *iter;
            } else
                last = *iter;
        }
        longest = max(longest, last - first + 1);

        return longest;
    }
};

//O(n) solution
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s(num.begin(), num.end()); //hash, expected O(n)
        int longest = 0;
        int first, last;

        for (auto item: s) {
            first = last = item;
            unordered_set<int>::iterator iter;
            while ((iter = s.find(first - 1)) != s.end()) { //e.g, 4, find 3, 2, 1...
                --first;
                s.erase(iter);
            }
            while ((iter = s.find(last + 1)) != s.end()) { //e.g., 4, find 5, 6, 7...
                ++last;
                s.erase(iter);
            }
            longest = max(longest, last - first + 1);
        }
        return longest;
    }
};
