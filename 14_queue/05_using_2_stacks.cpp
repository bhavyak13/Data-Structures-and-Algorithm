#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
class Stack
{
public:
    struct Node *top = NULL;
    void Push(int x);
    int Pop(void);
    int peek(int index);
    int stacktop(void);
    bool isempty(void);
    bool isfull(void);
};
void Stack::Push(int x)
{
    struct Node *tem = new Node;
    tem->data = x;
    tem->next = NULL;
    if (top != NULL)
        tem->next = top;
    top = tem;
}
bool Stack::isempty(void)
{
    if (top != NULL)
        return false;
    return true;
}
int Stack::Pop(void)
{
    int x = -1;
    if (top != NULL)
    {
        struct Node *tem = top;
        x = top->data;
        top = top->next;
        delete tem;
    }
    else
    {
        cout << "Stack Underflow!\n";
    }
    return x;
}
int Stack::peek(int index)
{
    if (top == NULL)
        return -1;
    struct Node *temp = top;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
            return -1;
    }
    return temp->data;
}
bool Stack::isfull(void)
{
    struct Node *t = new Node;
    if (t)
    {
        delete t;
        return false;
    }
    return true;
}
int Stack::stacktop(void)
{
    if (top != NULL)
    {
        return top->data;
    }
    return -1;
}

class Queue
{
private:
    Stack s1, s2;

public:
    void enQueue(int x);
    int deQueue(void);
    int first(void);
    bool isempty(void);
    void display(void);
};
void Queue::display(void)
{
    if (isempty())
    {
        cout << "Queue Empty\n";
        return;
    }
    Node *t = s2.top;
    while (!s1.isempty())
        s2.Push(s1.Pop());
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}
bool Queue::isempty(void)
{
    if (s1.isempty())
        if (s2.isempty())
            return true;
    return false;
}
void Queue::enQueue(int x)
{
    s1.Push(x);
}
int Queue::deQueue(void)
{
    if (s2.isempty())
    {
        if (s1.isempty())
        {
            cout << "Queue Empty";
            return -1;
        }
        while (!s1.isempty())
            s2.Push(s1.Pop());
    }
    return s2.Pop();
}
int Queue::first(void)
{
    if (s2.isempty())
    {
        if (s1.isempty())
            return -1;
        else
        {
            while (!s1.isempty())
            {
                s2.Push(s1.Pop());
            }
        }
    }
    return s2.stacktop();
}
int main()
{
    int n;
    Queue h;
    do
    {
        cout << "\n\nQUEUE!\n";
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. first\n";
        cout << "4. Display\n";
        cout << "5. isempty?\n";
        cout << "6. Exit\n";
        cout << "Enter your Choise: ";
        cin >> n;
        int x;
        switch (n)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            h.enQueue(x);
            break;
        case 2:
            x = h.deQueue();
            if (x != -1)
                cout << x << " has been Dequeued out of the Queue\n";
            break;
        case 3:
            cout << h.first();
            break;
        case 4:
            h.display();
            break;
        case 5:
            cout << h.isempty();
            break;
        default:
            break;
        }
    } while (n != 6);
    return 0;
}