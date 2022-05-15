#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
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

class tree
{
private:
    struct Node *root = NULL;
    Queue<Node *> q1;

public:
    Node *create(void);
    void preorder(Node *t);
    void postorder(Node *t);
    void inorder(Node *t);
    void iterative_preorder(Node *t);
    void iterative_postorder(Node *t);
    void iterative_inorder(Node *t);
    void levelorder(Node *t);
    int count_nodes(Node *t);
    int count_nodes_of_degree_2(Node *t);
    int sum(Node *t);
    int height(Node *t);
    int leaf_nodes(Node *t);
};
int tree::leaf_nodes(Node *t)
{
    if (t)
    {
        int x = leaf_nodes(t->lchild);
        int y = leaf_nodes(t->rchild);
        if (t->lchild == NULL && t->rchild == NULL)
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}
int tree::height(Node *t)
{
    int x, y;
    if (t != NULL)
    {
        x = height(t->lchild);
        y = height(t->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}
int tree::count_nodes_of_degree_2(Node *t)
{
    int x, y;
    if (t != NULL)
    {
        x = count_nodes_of_degree_2(t->lchild);
        y = count_nodes_of_degree_2(t->rchild);
        if (t->lchild && t->rchild)
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}
int tree::count_nodes(Node *t)
{
    int x, y;
    if (t != NULL)
    {
        x = count_nodes(t->lchild);
        y = count_nodes(t->rchild);
        return x + y + 1;
    }
    return 0;
}
int tree::sum(Node *t)
{
    int x, y;
    if (t != NULL)
    {
        x = sum(t->lchild);
        y = sum(t->rchild);
        return x + y + t->data;
    }
    return 0;
}
void tree::preorder(Node *t)
{
    if (t == NULL)
    {
        return;
    }
    cout << t->data << " ";
    preorder(t->lchild);
    preorder(t->rchild);
}
void tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}
void tree::inorder(Node *t)
{
    if (t != NULL)
    {
        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
    }
}
Node *tree::create(void)
{
    int x;
    struct Node *p = NULL;
    cout << "Enter data : ";
    cin >> x;
    if (root == NULL)
    {
        root = new Node;
        root->data = x;
        root->lchild = NULL, root->rchild = NULL;
    }
    q1.enQueue(root);
    while (!q1.isempty())
    {
        p = q1.deQueue();
        cout << "Enter left child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            struct Node *t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q1.enQueue(t);
        }
        cout << "Enter right child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            struct Node *t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            q1.enQueue(t);
            p->rchild = t;
        }
    }
    return root;
}
void tree::iterative_preorder(Node *t)
{
    Stack<Node *> s1;
    while (!s1.isempty() || t != NULL)
    {
        if (t == NULL)
        {
            t = s1.Pop();
            t = t->rchild;
        }
        if (t != NULL)
        {
            cout << t->data << " ";
            s1.Push(t);
            t = t->lchild;
        }
    }
}
void tree::iterative_inorder(Node *t)
{
    Stack<Node *> s1;
    while (!s1.isempty() && t != NULL)
    {
        if (t == NULL)
        {
            t = s1.Pop();
            cout << t->data;
            t = t->rchild;
        }
        if (t != NULL)
        {
            s1.Push(t);
            t = t->lchild;
        }
    }
}
void tree::iterative_postorder(Node *t)
{
    // used predefined stack not that which is
    // included in the top of current code!!
    stack<pair<Node *, int>> s1;
    while (!s1.empty() || t != NULL)
    {
        if (t != NULL)
        {
            s1.push(make_pair(t, 1));
            t = t->lchild;
        }
        if (t == NULL)
        {
            auto x = s1.top();
            s1.pop();
            t = x.first;
            if (x.second > 0)
            {
                s1.push(make_pair(t, -1));
                t = t->rchild;
            }
            else
            {
                cout << t->data << " ";
                t = NULL;
            }
        }
    }
}
void tree::levelorder(Node *t)
{
    Queue<Node *> q1;
    cout << t->data << " ";
    q1.enQueue(t);
    while (!q1.isempty())
    {
        t = q1.deQueue();
        if (t->lchild != NULL)
        {
            cout << t->lchild->data << " ";
            q1.enQueue(t->lchild);
        }
        if (t->rchild != NULL)
        {
            cout << t->rchild->data << " ";
            q1.enQueue(t->rchild);
        }
    }
}
int main()
{
    tree t1;
    Node *root = t1.create();
    t1.levelorder(root);
    cout << t1.sum(root) << endl;
    cout << t1.count_nodes(root) << endl;
    cout << t1.count_nodes_of_degree_2(root) << endl;
    cout << t1.height(root) << endl;
    cout << t1.leaf_nodes(root) << endl;
    // t1.iterative_postorder(root);
    return 0;
}