#include <iostream>

using namespace std;

int insert(int m, int n, int i, int j)  //move n
{
    int lowest = n & ((1 << i) - 1);
    n = (n >> i) & (~0 << (j - i));
    return ((n  | m) << i) | lowest;
}

int insert2(int m, int n, int i, int j)  //move m
{
    int mask = (1 << (j + 1)) - 1;
    mask = mask & ~((1 << (i + 1)) - 1);
    return (n & ~mask) | (m << i);
}

int insert3(int m, int n, int i, int j) //solution from the book
{
    int allOnes = ~0;
    int left = allOnes << (j + 1);
    int right = ((1 << i) - 1);
    int mask = left | right;
    int nCleared = n & mask;
    int mShifted = m << i;
    return nCleared | mShifted;
}

int main(int argc, char *argv[])
{
    int m = 0x13, n = 0x400, l = 0x43c;
    cout.setf(ios_base::hex, ios_base::basefield);
    cout.setf(ios_base::showbase);
    cout << insert(m, n, 2, 6) << endl;
    cout << insert(m, l, 2, 6) << endl;
    cout << insert2(m, n, 2, 6) << endl;
    cout << insert2(m, l, 2, 6) << endl;
    cout << insert3(m, n, 2, 6) << endl;
    cout << insert3(m, l, 2, 6) << endl;
    return 0;
}
