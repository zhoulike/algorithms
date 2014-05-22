class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (auto s: strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());  //sort: O(mlogm)
            map[tmp].push_back(s);
        }

        vector<string> ans;
        for (auto pair: map) {
            if (pair.second.size() > 1)
                copy(pair.second.begin(), pair.second.end(), back_inserter(ans));
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (auto s: strs) {
            string hash_code = compress(s); //Compress: O(m)
            map[hash_code].push_back(s);
        }

        vector<string> ans;
        for (auto pair: map) {
            if (pair.second.size() > 1)
                copy(pair.second.begin(), pair.second.end(), back_inserter(ans));
        }

        return ans;
    }
private:
    string compress(string& s) { //"ababccc" -> "2a2b3c"
        vector<int> v(26, 0);
        for (auto ch: s)
            ++v[ch - 'a'];
        stringstream sstrm;
        for (int i = 0; i < v.size(); ++i)
            if (v[i] > 0)
                sstrm << v[i] << 'a' + i;

        return sstrm.str();
    }
};
