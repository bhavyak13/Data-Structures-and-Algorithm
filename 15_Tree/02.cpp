#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
template <class t>
class node
{
public:
    t data;
    node *next;
};
template <class t>
class Stack
{
private:
    node<t> *top = NULL;

public:
    void Push(t x);
    t Pop(void);
    bool isempty(void);
    bool isfull(void);
};
template <class t>
void Stack<t>::Push(t x)
{
    node<t> *tem = new node<t>;
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
    int x = -1;
    if (top != NULL)
    {
        node<t> *tem = top;
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
    node<t> *t = new node<t>;
    if (t)
    {
        delete t;
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