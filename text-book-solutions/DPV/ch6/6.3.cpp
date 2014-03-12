#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &dis, vector<int> &profit, int k)
{
    if (dis.size() == 0)
        return 0;
    
    vector<int> p(dis.size(), 0);
    p[0] = profit[0];

    for (int i = 1; i < dis.size(); ++i) {
        for (int j = 0; j < i && dis[i] - dis[j] >= k; ++j) {
            p[i] = max(p[i], p[j] + profit[i]);            
        }
    }

    return p.back();
}

int main(int argc, char *argv[])
{
    int a[] = {10, 20, 30, 50, 80, 100},
        b[] = {20, 10, 20, 30, 20, 30};

    vector<int> dis(a, a + 6), profit(b, b + 6);

    cout << maxProfit(dis, profit, 20) << endl;
    return 0;
}
