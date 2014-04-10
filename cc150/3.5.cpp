#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    void push(int value);
    int pop();
    bool empty() const
    {
        return sIn.empty() && sOut.empty();
    }

private:
    stack<int> sIn, sOut;
};

void MyQueue::push(int value)
{
    sIn.push(value);
}

int MyQueue::pop()
{
    if (sOut.empty()) {
        while (!sIn.empty()) {
            sOut.push(sIn.top());
            sIn.pop();
        }
    }

    int val = sOut.top();
    sOut.pop();
    return val;
}

void test()
{
    MyQueue q;

    cout << "push 0~9." << endl;
    for (int i = 0; i < 10; ++i)
        q.push(i);

    cout << "pop 0~3: ";
    for (int i = 0; i < 4; ++i)
        cout << q.pop() << " ";

    cout << endl << "push 10~19." << endl;
    for (int i = 10; i < 20; ++i)
        q.push(i);

    cout << "pop all: ";
    while (!q.empty()) 
        cout << q.pop() << " ";
    cout << endl;
}


int main(int argc, char *argv[])
{
    test();
    return 0;
}
