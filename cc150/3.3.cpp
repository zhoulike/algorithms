#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks
{
public:
    SetOfStacks (int cap = 128) :capacity(cap), curr(1)
    {
        stacks.push_back(stack<int>());
    }

    void push(int value);
    int pop();
    int popAt(int index);

    bool empty() const
    {
        return curr == 1 && stacks[curr - 1].empty();
    }

    int size() const
    {
        return curr;
    }

private:
    vector<stack<int> > stacks;
    int curr;
    int capacity;
};

void SetOfStacks::push(int value)
{
    if (stacks[curr - 1].size() == capacity) {
        stacks.push_back(stack<int>());
        ++curr;
    } 
    stacks[curr - 1].push(value);
}

int SetOfStacks::pop()
{
    return popAt(curr - 1);
}

int SetOfStacks::popAt(int index)
{
    //popAt does not include rollover.
    //If we want to implement rollover, we need to use deque, not stack.
    if (index >= 0 && index < curr) {
        int val = stacks[index].top();
        stacks[index].pop();

        if (stacks[index].empty() && curr > 1) { //keep at least 1 stack
            stacks.erase(stacks.begin() + index);
            --curr;
        }

        return val;
    }
}



void test(int num)
{
    SetOfStacks s;
    for (int i = 0; i < num; ++i)
        s.push(i);

    cout << "size: " << s.size() << endl;

    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
}

void testPopAt()
{
    SetOfStacks s(2);
    for (int i = 0; i < 10; ++i)
        s.push(i);

    cout << "size: " << s.size() << endl;
    cout << s.popAt(0) << endl;
    cout << s.popAt(0) << endl;
    cout << "size: " << s.size() << endl;

    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    test(10);
    test(128);
    test(129);

    testPopAt();
    return 0;
}
