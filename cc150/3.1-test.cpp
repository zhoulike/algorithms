#include <iostream>
#include <cstring>
#include "3.1.h"

using namespace std;

void test(int num)
{
    stack s;
    for (int i = 0; i < num; ++i)
        s.push(i);

    while(!s.empty())
        cout << s.pop() << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    test(1);
    test(100);
    test(129);
    test(256);
    return 0;
}
