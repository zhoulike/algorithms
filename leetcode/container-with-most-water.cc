/*
 *类似于2sum，设置首尾指针。计算当前水的容量，然后移动短板。
 *只有移动短板才能尝试找到更长的板，从而装更多的水。
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2)
            return 0;

        int water = 0;
        int i = 0, j = height.size() - 1;
        
        while (i < j) {
            water = max(water, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }

        return water;
    }
};
