#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class Queue
{
private:
    node *front = NULL, *rear = NULL;

public:
    void enQueue(int x);
    int deQueue(void);
    int last(void);
    int first(void);
    bool isempty(void);
    bool isfull(void);
    void display(void);
};
void Queue::display(void)
{
    if (isempty())
    {
        cout << "Queue Empty\n";
        return;
    }
    for (node *i = front; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
}
int Queue::last(void)
{
    if (isempty())
        return -1;
    return rear->data;
}
bool Queue::isempty(void)
{
    if (front == NULL)
        return true;
    return false;
}
bool Queue::isfull(void)
{
    node *t = new node;
    if (t == NULL)
        return true;
    delete t;
    return false;
}
void Queue::enQueue(int x)
{
    if (isfull())
    {
        cout << "Queue full";
        return;
    }
    node *t = new node;
    t->data = x;
    t->next = NULL;
    if (isempty())
        rear = front = t;
    else
    {
        rear->next = t;
        rear = t;
    }
}
int Queue::deQueue(void)
{
    int x = -1;
    if (isempty())
        cout << "Queue Empty" << endl;
    else
    {
        x = front->data;
        node *t = front;
        front = front->next;
        delete t;
    }
    return x;
}
int Queue::first(void)
{
    if (isempty())
        return -1;
    return front->data;
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
        cout << "4. last\n";
        cout << "5. isempty?\n";
        cout << "6. isfull?\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your Choise: ";
        cin >> n;
        int x;
        switch (n)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            if (!h.isfull())
                cout << x << " is queued into the queue!\n";
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
            cout << h.last();
            break;
        case 5:
            cout << h.isempty();
            break;
        case 6:
            cout << h.isfull();
            break;
        case 7:
            h.display();
            break;
        default:
            break;
        }
    } while (n != 8);
    return 0;
}