class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1)
            return;

        auto pos1 = num.end(), pos2 = num.end() - 1;
        for (auto pos = num.end() - 2; pos >= num.begin(); --pos) {  //1
            if (*pos < *pos2) {
                pos1 = pos;
                break;
            } else if (*pos > *pos2)
                pos2 = pos;
        }

        if (pos1 == num.end())
            sort(num.begin(), num.end());
        else {
            for (auto pos = pos1 + 1; pos != num.end(); ++pos) {  //2
                if (*pos > *pos1 && *pos < *pos2)
                    pos2 = pos;
            }

            swap(*pos1, *pos2);
            sort(pos1 + 1, num.end());  //3
        }
    }
};


//前面1,2,3这三个位置都可以优化的。
class Solution2 {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1)
            return;

        //优化1：只需要找到（从后面开始）第一个num[i] < num[i + 1]的位置i即可。
        //比如2355541,只要找到3就可以了，不需要再找到2去。找到2去就错了。
        //还要注意的是，[i+1, end)这一段元素都是递减的。
        auto pos1 = num.end() - 2;
        while (pos1 >= num.begin() && *pos1 >= *(pos1 + 1))
            --pos1;

        if (pos1 < num.begin())
            sort(num.begin(), num.end());
        else {
            //优化2：只需要找到（从后面开始)第一个num[j] > num[i]的位置j即可。
            //比如2355541，只要找到4就可以了。
            auto pos2 = num.end() - 1;
            while (pos2 > pos1 && *pos2 <= *pos1)
                --pos2;

            swap(*pos1, *pos2);
            //优化3：不需要使用时间复杂度高的sort。
            //由于[i+1, end)之间是递减的，上面这一步交换后仍然递减。
            //所以只需要从两端开始交换，逆转这一段元素，就相当于排好序。
            for (pos1 = pos1 + 1, pos2 = num.end() - 1; pos1 < pos2; ++pos1, --pos2)
                swap(*pos1, *pos2);
        }
    }
};
