#ifndef STACK_INCLUDED
#define STACK_INCLUDED

class Stack
{
    int *arr;
    const size_t size;
    size_t cur_size;
public:
    Stack (int n = 100)
        :size(n), cur_size(0)
    {
        arr = new int[size];
    }
    bool empty()
    {
        return cur_size == 0;
    }
    bool full()
    {
        return cur_size = size;
    }
    void push(int val)
    {
        if (!full())
            arr[cur_size++] = val;
    }
    void pop()
    {
        if (!empty())
            arr[cur_size--] = 0;
    }
    int top()
    {
        if (!empty())
            return arr[cur_size - 1];
    }
    ~Stack()
    {
        delete arr;
    }
};


#endif  //STACK_INCLUDED
