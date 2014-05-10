class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> map(numbers.size());
        for (int i = 0; i < numbers.size(); ++i)
            map[i] = {numbers[i], i};

        sort(map.begin(), map.end(), 
                [](const pair<int, int>& lhs, const pair<int, int>& rhs) 
                {return lhs.first < rhs.first;});

        vector<int> ans;
        for (int i = 0; i < map.size(); ++i) {
            int j = binary_search(map, i + 1, map.size() - 1, target - map[i].first);
            if (j != -1) {
                ans.push_back(min(map[i].second + 1, map[j].second + 1));
                ans.push_back(max(map[i].second + 1, map[j].second + 1));
                break;
            }
        }

        return ans;
    }
private:
    int binary_search(vector<pair<int, int>> &map, int low, int high, int target)
    {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (map[mid].first == target)
                return mid;
            else if (map[mid].first < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};
