#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
class Stack
{
private:
    struct node *top = NULL;

public:
    void Push(int x);
    void create(int *Arr, int len);
    int Pop(void);
    int peek(int index);
    int stacktop(void);
    bool isempty(void);
    bool isfull(void);
};
void Stack::Push(int x)
{
    struct node *tem = new node;
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
        struct node *tem = top;
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
    struct node *temp = top;
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
    struct node *t = new node;
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

int main()
{
    int n = 6;
    Stack h;
    do
    {
        cout << "STACK!\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Stack Top\n";
        cout << "5. Is empty?\n";
        cout << "6. Exit\n";
        cout << "Enter your Choise: ";
        cin >> n;
        int x;
        switch (n)
        {
        case 2:
            cout << h.Pop() << " has been poped out of the Stack\n";
            break;
        case 1:
            cout << "Enter value: ";
            cin >> x;
            h.Push(x);
            cout << x << " is pushed into the STACK\n";
            break;
        case 3:
            cout << "Enter Position: ";
            cin >> x;
            cout << h.peek(x);
            break;
        case 4:
            cout << h.stacktop();
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