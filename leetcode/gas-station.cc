class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() <= 0)
            return -1;

        vector<int> remain(gas.size(), 0);
        for (int i = 0; i < gas.size(); ++i)   //计算每个站点剩下的油
            remain[i] = gas[i] - cost[i];

        int start = 0, end = 0;
        int total = remain[0];
        while ((end + 1) % gas.size() != start) {
            if (total < 0) {  //当前油不够，start往前走，多累积点
                start = (start - 1 + gas.size()) % gas.size();
                total += remain[start];
            } else  //油够往后走
                total += remain[++end];
        }

        return total >= 0? start: -1;
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() <= 0)
            return -1;

        int start = 0;
        int total = 0, tank = 0;
        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (tank < 0) {  //油不够了，起点可能是当前站点的下一个，由后面补齐啊
                tank = 0;
                start = i + 1;
            }
        }

        return total >= 0? start: -1;
    }
};
