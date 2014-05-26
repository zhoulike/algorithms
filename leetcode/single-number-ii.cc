//time: O(n), space: O(n)
class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> times;
        for (int i = 0; i < n; ++i)
            ++times[A[i]];

        for (auto iter = times.begin(); iter != times.end(); ++iter)
            if (iter->second != 3)
                return iter->first;
    }
};

//模拟三进制和异或
//ones代表1出现1次，twos代表1出现2次
//当ones和twos同一位为1时，说明出现了3次了，需要清零。threes用来清除该位的1。
class Solution2 {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0;
        for (int i = 0; i < n; ++i) {
            twos |= ones & A[i];   //ones中的1出现2次时进位到twos
            ones ^= A[i];         //ones中的1出现2次，进位后要清零
            int threes = ~(ones & twos);  //ones和twos中同为1的位取反
            ones &= threes;  //清除ones和twos中同为1的位，相当于异或
            twos &= threes;
        }

        return ones;  //如果某个数是出现两次就返回twos
    }
};
