#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int top;
    int size;
    int *st;
};
class Stack
{
private:
    node *p = new node;

public:
    Stack(int size)
    {
        p->size = size;
        p->top = -1;
        p->st = new int[size];
    }
    void Push(int x);
    int Pop(void);
    int peek(int index);
    int stacktop(void);
    bool isempty(void);
    bool isfull(void);
};
void Stack::Push(int x)
{
    if (p->top == p->size - 1)
    {
        cout << "Stack overflow!!" << endl;
    }
    else
    {
        p->st[++p->top] = x;
    }
}
int Stack::Pop(void)
{
    int x = -1;
    if (p->top == -1)
    {
        cout << "Stack Underflow!!" << endl;
    }
    else
    {
        x = p->st[p->top--];
    }
    return x;
}
int Stack::peek(int index)
{
    int x = -1;

    if (p->top - index + 1 < 0)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        x = p->st[p->top - index + 1];
    }
    return x;
}
int Stack::stacktop(void)
{
    int x = -1;
    if (p->top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = p->st[p->top];
    }
    return x;
}
bool Stack::isempty(void)
{
    if (p->top == -1)
    {
        return true;
    }
    return false;
}
bool Stack::isfull(void)
{
    if (p->top == p->size - 1)
    {
        return true;
    }
    return false;
}

int main()
{
    Stack s1(5);
    cout << s1.isempty() << endl;
    s1.Push(8);
    s1.Push(7);
    s1.Push(6);
    s1.Push(7);
    s1.Push(2);
    s1.Push(7);
    cout << s1.stacktop() << endl;
    cout << s1.peek(5) << endl;
    cout << s1.isfull() << endl;
    cout << s1.isempty() << endl;
    s1.Pop();
    cout << s1.isfull() << endl;
    cout << s1.peek(1) << endl;
    cout << s1.stacktop() << endl;
    return 0;
}