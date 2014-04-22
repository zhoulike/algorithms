#include <iostream>
#include <vector>

using namespace std;

int staircase_ways(int n) {
    if (n <= 0)
        return 0;

    vector<int> ways(n + 1);
    ways[0] = 1;

    for (int i = 1; i < ways.size(); ++i) {
        if (i - 1 >= 0)
            ways[i] += ways[i - 1];
        if (i - 2 >= 0)
            ways[i] += ways[i - 2];
        if (i - 3 >= 0)
            ways[i] += ways[i - 3];
    }

    return ways.back();
}

void test(int n)
{
    cout << n << " steps, " << staircase_ways(n) << " ways." << endl;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; ++i)
        test(i);
    return 0;
}
