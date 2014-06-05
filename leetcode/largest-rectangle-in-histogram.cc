//naive solution: O(n^2). Time Limit Exceeded
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty())
            return 0;

        int max_area = INT_MIN;
        for (auto first = height.begin(); first != height.end(); ++first) {
            int min_histogram = *first;
            max_area = max(max_area, *first);
            for (auto last = first + 1; last != height.end(); ++last) {
                min_histogram = min(min_histogram, *last);
                max_area = max(max_area, static_cast<int>(min_histogram * (last - first + 1)));
            }
        }

        return max_area;
    }
};

//faster, but Time Limit Exceeded
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return helper(height.begin(), height.end());
    }
private:
    int helper(vector<int>::const_iterator first, vector<int>::const_iterator last) {
        if (first == last)
            return 0;

        auto min_histogram = min_element(first, last);
        int total = (last - first) * (*min_histogram),
            left_half = helper(first, min_histogram),
            right_half = helper(min_histogram + 1, last);

        return max(max(total, left_half), right_half);
    }
};

//O(n) solution
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0); //dummy histogram
        int max_area = 0;
        stack<int> stk;
        for (int i = 0; i < height.size();) {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else {
                int pos = stk.top();
                stk.pop();
                max_area = max(max_area, height[pos] * (stk.empty()? i: i - stk.top() - 1));
            }
        }
        height.pop_back(); //restore vector
        return max_area;
    }
};
