class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majority, count = 0;
        for (auto item: num) {
            if (count == 0) {
                ++count;
                majority = item;
            } else if (majority == item)
                ++count;
            else
                --count;
        }
        return majority;
    }
};
