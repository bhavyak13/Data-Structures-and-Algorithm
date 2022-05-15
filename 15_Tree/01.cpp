#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
template <class T>
class node
{
public:
    T data;
    node *next;
};
template <class T>
class Queue
{
private:
    node<Node *> *front = NULL, *rear = NULL;

public:
    void enQueue(T x);
    T deQueue(void);
    bool isempty(void);
    bool isfull(void);
};
template <class T>
bool Queue<T>::isempty(void)
{
    if (front == NULL)
        return true;
    return false;
}
template <class T>
bool Queue<T>::isfull(void)
{
    node<Node *> *t = new node<Node *>;
    if (t == NULL)
        return true;
    delete t;
    return false;
}
template <class T>
void Queue<T>::enQueue(T x)
{
    if (isfull())
    {
        cout << "Queue full";
        return;
    }
    node<Node *> *t = new node<Node *>;
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
template <class T>
T Queue<T>::deQueue(void)
{
    T x = NULL;
    if (isempty())
        cout << "Queue Empty" << endl;
    else
    {
        x = front->data;
        node<Node *> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

class bt
{
private:
    Node *root = NULL;
    Queue<Node *> q1;
    Queue<Node *> q2;

public:
    Node *create(void);
    void display(void);
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void levelorder(void);
};
void bt::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}
void bt::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
void bt::levelorder(void)
{
    Queue<Node *> q = q2;
    while (!q.isempty())
    {
        cout << q.deQueue()->data << " ";
    }
}
Node *bt::create(void)
{
    int x;
    Node *p = NULL, *q = NULL;
    cout << "Enter data : ";
    root = new Node;
    cin >> root->data;
    root->lchild = NULL;
    root->rchild = NULL;
    q1.enQueue(root);
    while (!q1.isempty())
    {
        q = q1.deQueue();
        q2.enQueue(q);
        cout << "Left Child of " << q->data << ": ";
        cin >> x;
        if (x != -1)
        {
            p = new Node;
            p->data = x;
            p->lchild = NULL;
            p->rchild = NULL;
            q->lchild = p;
            q1.enQueue(p);
        }
        cout << "Right Child of " << q->data << ": ";
        cin >> x;
        if (x != -1)
        {
            p = new Node;
            p->data = x;
            p->rchild = NULL;
            p->lchild = NULL;
            q->rchild = p;
            q1.enQueue(p);
        }
    }
    return root;
}
void bt::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void bt::display(void)
{
    Node *q = NULL;
    Queue<Node *> q3;
    while (!q2.isempty())
    {
        q = q2.deQueue();
        q3.enQueue(q);
        cout << "\nNode: ";
        cout << q->data;
        if (q->lchild != NULL)
        {
            cout << "\nLeft Child of " << q->data << ": ";
            cout << q->lchild->data;
        }
        if (q->rchild != NULL)
        {
            cout << "\nRight Child of " << q->data << ": ";
            cout << q->rchild->data;
        }
    }
    cout << "\n";
    q2 = q3;
}
int main()
{
    bt b;
    Node *root = b.create();
    b.display();
    cout << endl;
    b.preorder(root);
    cout << endl;
    b.postorder(root);
    cout << endl;
    b.levelorder();
    return 0;
}