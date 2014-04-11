#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

void sort_stack(stack<int> &stk)
{
    //this sort algorithm seems like selection sort.
    int size = stk.size();
    stack<int> tmp;

    while (size > 0) {
        //find minimum
        int min = stk.top();
        stk.pop();

        for (int i = 0; i < size - 1; ++i) {
            int val = stk.top();
            stk.pop();

            if (min < val) {
                tmp.push(val);
            } else {
                tmp.push(min);
                min = val;
            }
        }

        stk.push(min);
        --size;

        if (size <= 0)
            break;

        //find maximum
        int max = tmp.top();
        tmp.pop();

        for (int i = 0; i < size - 1; ++i) {
            int val = tmp.top();
            tmp.pop();
            
            if (max > val) {
                stk.push(val);
            } else {
                stk.push(max);
                max = val;
            }
        }

        tmp.push(max);
        --size;
    }

    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }
}

void sort_stack2(stack<int> &stk)
{
    //this sort alogirhtm from CC150, which seems like insertion sort, 
    //is much more simple and efficient.
    //It conducts less pops than previous algorithm.
    stack<int> tmp(stk);
    stk = stack<int>();

    while (!tmp.empty()) {
        int val = tmp.top();
        tmp.pop();

        while (!stk.empty() && stk.top() > val) {
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(val);
    }
}

void test(int n)
{
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        s.push(rand());
    }
    stack<int> s2(s);

    sort_stack(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    sort_stack2(s2);

    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}


int main(int argc, char *argv[])
{
    test(0);
    test(1);
    test(10);
    test(20);
    return 0;
}
