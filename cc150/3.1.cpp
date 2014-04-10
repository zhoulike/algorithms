#include <iostream>
#include <cstring>

using namespace std;

class stack
{
public:
    stack () :curr(0), capacity(default_size)
    {
        data = new int[capacity];
    }
    
    virtual ~stack ()
    {
        delete [] data;
    }

    void push(int value);
    int pop();
    bool empty() const;

private:
    static const int default_size = 128;
    int *data;
    int curr, capacity;
};

const int stack::default_size;

void stack::push(int value)
{
    if (curr == capacity) {
        int new_capacity = capacity * 2;
        int *new_data = new int[new_capacity];
        memcpy(new_data, data, capacity * sizeof(int)); 
        delete [] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[curr++] = value;
}

int stack::pop()
{
    if (curr > 0)
        return data[--curr];
}

bool stack::empty() const
{
    return curr == 0;
}


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
