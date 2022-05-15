#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int size;
    int front;
    int rear;
    int *s;
};
class CQueue
{
private:
    node *q = NULL;

public:
    CQueue(int n)
    {
        q = new node;
        q->size = n;
        q->front = 0;
        q->rear = 0;
        q->s = new int[q->size];
    }
    void create(int *arr);
    void enQueue(int x);
    void display(void);
    int deQueue(void);
    int last(void);
    int first(void);
    bool isempty(void);
    bool isfull(void);
    ~CQueue(void)
    {
        delete[] q->s;
    }
};
void CQueue::display(void)
{
    if (isempty())
    {
        cout << "Queue Empty\n";
        return;
    }
    int i = q->front;
    if (q->front == q->size - 1)
        i = -1;
    for (i++; i != q->rear + 1; i++)
    {
        cout << q->s[i] << " ";
        if (i == q->size - 1 && i != q->rear)
        {
            i = -1;
        }
    }
}
int CQueue::last(void)
{
    if (isempty())
        return -1;
    return q->s[q->rear];
}
bool CQueue::isempty(void)
{
    if (q->front == q->rear)
        return true;
    return false;
}
bool CQueue::isfull(void)
{
    if ((q->rear + 1) % q->size == q->front)
        return true;
    return false;
}
void CQueue::create(int *arr)
{
    for (int i = 0; i < q->size; i++)
    {
        q->s[i] = arr[i];
        q->rear++;
    }
}
void CQueue::enQueue(int x)
{
    if (isfull())
    {
        cout << "Queue full";
        return;
    }
    q->rear == (q->rear + 1) % q->size;
    q->s[q->rear] = x;
}
int CQueue::deQueue(void)
{
    if (isempty())
    {
        cout << "Queue Empty" << endl;
        return -1;
    }
    q->front == (q->front + 1) % q->size;
    return q->s[q->front];
}
int CQueue::first(void)
{
    if (isempty())
        return -1;
    int x = q->front;
    return q->s[++x];
}
int main()
{
    int n;
    CQueue h(5);
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