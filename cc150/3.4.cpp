#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void hanoi_iter(stack<int> &a, stack<int> &b, stack<int> &c, int disks)
{
    //a -> c, b is a temporary tower
    if (disks <= 0)
        return;

    hanoi_iter(a, c, b, disks - 1);
    int val = a.top();
    a.pop();
    c.push(val);
    hanoi_iter(b, a, c, disks - 1);
}

void hanoi(int n)
{
    vector<stack<int> > v(3);
    for (int i = 1; i <= n; ++i)
        v[0].push(i);

    hanoi_iter(v[0], v[1], v[2], n);

    while (!v[2].empty()) {
        cout << v[2].top() << " ";
        v[2].pop();
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    hanoi(8);
    return 0;
}
