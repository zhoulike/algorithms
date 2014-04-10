#include "3.1.h"

class stackWithMin : public stack
{
public:
    void push(int value);
    int pop();
    int min() const;

private:
    stack minimum; //store the index of minimum value in data[]
};

void stackWithMin::push(int value)
{
    if (minimum.empty() || min() > value) { //don't forget empty
        minimum.push(curr);
    } 
    stack::push(value);
}

int stackWithMin::pop()
{
    if (curr > 0) {
        if (curr - 1 == minimum.top())
            minimum.pop();
        return stack::pop();
    }
}

int stackWithMin::min() const
{
    if (!minimum.empty()) {
        return data[minimum.top()];
    }
}
