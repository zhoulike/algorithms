#include <cstring>

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
    int top() const;

protected:
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

int stack::top() const
{
    if (curr >= 0)
        return data[curr - 1];
}

bool stack::empty() const
{
    return curr == 0;
}
