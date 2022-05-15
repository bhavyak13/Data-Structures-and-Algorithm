#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
class node
{
public:
    int size;
    int front;
    int rear;
    int *s;
};
class Queue
{
private:
    node *q = NULL;

public:
    Queue(int n)
    {
        q = new node;
        q->size = n;
        q->front = -1;
        q->rear = -1;
        q->s = new int[q->size];
    }
    void create(int *arr);
    void enQueue(int x);
    int deQueue(void);
    int last(void);
    int first(void);
    bool isempty(void);
    bool isfull(void);
    ~Queue(void)
    {
        delete[] q->s;
    }
};
int Queue::last(void)
{
    if (isempty())
        return -1;
    return q->s[q->rear];
}
bool Queue::isempty(void)
{
    if (q->front == q->rear)
        return true;
    return false;
}
bool Queue::isfull(void)
{
    if (q->rear == q->size - 1)
        return true;
    return false;
}
void Queue::create(int *arr)
{
    for (int i = 0; i < q->size; i++)
    {
        q->s[i] = arr[i];
        q->rear++;
    }
}
void Queue::enQueue(int x)
{
    if (isfull())
    {
        cout << "Queue full";
        return;
    }
    q->s[++q->rear] = x;
}
int Queue::deQueue(void)
{
    if (isempty())
    {
        cout << "Queue Empty" << endl;
        return -1;
    }
    return q->s[++q->front];
}
int Queue::first(void)
{
    if (isempty())
        return -1;
    int x = q->front;
    return q->s[++x];
}
int main()
{
    int n = 7;
    Queue h(5);
    do
    {
        cout << "QUEUE!\n";
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. first\n";
        cout << "4. last\n";
        cout << "5. isempty?\n";
        cout << "6. isfull?\n";
        cout << "7. Exit\n";
        cout << "Enter your Choise: ";
        cin >> n;
        int x;
        switch (n)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            h.enQueue(x);
            cout << x << " is queued into the queue!\n";
            break;
        case 2:
            cout << h.deQueue() << " has been Dequeued out of the Queue\n";
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
        default:
            break;
        }
    } while (n != 7);
    return 0;
}