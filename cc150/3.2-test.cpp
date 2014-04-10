#include <iostream>
#include <cstring>
#include <cstdlib>
#include "3.2.h"

using namespace std;

void test(int num)
{
    stackWithMin s;
    for (int i = 1; i <= num; ++i)
        s.push(i);

    while(!s.empty()) {
        cout << " min: " << s.min();
        cout << " pop: " << s.pop() << endl;
    }
}

void test_reverse(int num)
{
    stackWithMin s;
    for (int i = num; i > 0; --i)
        s.push(i);

    while(!s.empty()) {
        cout << " min: " << s.min();
        cout << " pop: " << s.pop() << endl;
    }
}

void test_random(int num)
{
    stackWithMin s;
    for (int i = num; i > 0; --i)
        s.push(rand());

    while(!s.empty()) {
        cout << " min: " << s.min();
        cout << " pop: " << s.pop() << endl;
    }
}

int main(int argc, char *argv[])
{
    test(1);
    test(100);
    test(129);
    test(256);
    test_reverse(256);
    test_random(10);
    return 0;
}
