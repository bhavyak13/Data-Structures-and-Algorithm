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

template <class t>
class nodes
{
public:
    t data;
    nodes *next;
};
template <class t>
class Stack
{
private:
    nodes<t> *top = NULL;

public:
    void Push(t x);
    t Pop(void);
    bool isempty(void);
    bool isfull(void);
};
template <class t>
void Stack<t>::Push(t x)
{
    nodes<t> *tem = new nodes<t>;
    tem->data = x;
    tem->next = NULL;
    if (top != NULL)
        tem->next = top;
    top = tem;
}
template <class t>
bool Stack<t>::isempty(void)
{
    if (top != NULL)
        return false;
    return true;
}
template <class t>
t Stack<t>::Pop(void)
{
    t x = NULL;
    if (top != NULL)
    {
        nodes<t> *tem = top;
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
template <class t>
bool Stack<t>::isfull(void)
{
    nodes<t> *t1 = new nodes<t>;
    if (t1)
    {
        delete t1;
        return false;
    }
    return true;
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
    void i_preorder(void);
    void i_postorder(void);
    void i_inorder(void);
    void i_levelorder(void);
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
void bt::i_preorder(void)
{
    Stack<Node *> s1;
    Node *t = root;
    while (!s1.isempty() || t != NULL)
    {
        if (t != NULL)
        {
            cout << t->data;
            s1.Push(t);
            t = t->lchild;
        }
        else
        {
            t = s1.Pop();
            t = t->rchild;
        }
    }
}
void bt::i_inorder(void)
{
    Stack<Node *> s1;
    Node *t = root;
    while (!s1.isempty() || t != NULL)
    {
        if (t != NULL)
        {
            s1.Push(t);
            t = t->lchild;
        }
        else
        {
            t = s1.Pop();
            cout << t->data;
            t = t->rchild;
        }
    }
}
void bt::i_postorder(void)
{
    Stack<Node *> s1;
    Node *t = root, *x = NULL;
    do
    {
        if (t != NULL)
        {
            s1.Push(t);
            t = t->lchild;
        }
        else
        {
            t = s1.Pop();
                t = t->rchild;
            if (t->rchild == NULL)
            {
                cout << t->data;
            }
            else
            {
                s1.Push(t);
            }
        }
    } while (!s1.isempty());
}

int main()
{
    bt b;
    b.create();
    b.i_postorder();
    return 0;
}
/*
do
    {
        if (r == NULL)
        {
            x = r = s1.Pop();
            r = r->rchild;
        }
        if (r != NULL)
        {
            s1.Push(r);
            r = r->lchild;
        }
        else
            cout << x->data;
    } while (!s1.isempty());
*/