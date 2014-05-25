class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int sum = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size() - 2; ++i) {
            int j = i + 1, k = num.size() - 1;
            int remain = target - num[i];
            while (j < k) {  //turns 3sum to 2sum
                int partial_sum = num[j] + num[k];
                if (partial_sum == remain)
                    return target;
                else if (partial_sum < remain)
                    ++j;
                else
                    --k;

                if (abs(partial_sum + num[i] - target) < abs(sum - target))
                    sum = partial_sum + num[i];
            }
        }

        return sum;
    }
};
