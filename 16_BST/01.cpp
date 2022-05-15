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

class bst
{
public:
    Node *insert(Node *p, int key);
    Node *inserti(Node *p, int key);
    Node *search(Node *p, int key);
    Node *searchi(Node *p, int key);
    Node *Delete(Node *p, int key);
    void inorder(Node *t)
    {
        if (t != NULL)
        {
            inorder(t->lchild);
            cout << t->data << " ";
            inorder(t->rchild);
        }
    }
    void levelorder(Node *t)
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
    int height(Node *t)
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
    Node *inopre(Node *t);
    Node *inosuc(Node *t);
    Node *CreFromPreorder(int *arr, int size);
};
Node *bst::CreFromPreorder(int *arr, int n)
{
    Node *root, *p = NULL;
    stack<Node *> s;
    if (n > 0)
    {
        root = new Node;
        root->data = arr[0];
        root->lchild = root->rchild = NULL;
        p = root;
    }
    int i = 1;
    while (i < n)
    {
        if (arr[i] < p->data)
        {
            Node *q = new Node;
            q->data = arr[i++];
            q->lchild = q->rchild = NULL;
            p->lchild = q;
            s.push(p);
            p = q;
        }
        else if (arr[i] > p->data)
        {
            if (s.empty() || arr[i] < s.top()->data)
            {
                {
                    Node *q = new Node;
                    q->data = arr[i++];
                    q->lchild = q->rchild = NULL;
                    p->rchild = q;
                    p = q;
                }
            }
            else
            {
                p = s.top();
                s.pop();
            }
        }
    }
    return root;
}
Node *bst::inopre(Node *p)
{
    while (p->rchild != NULL && p != NULL)
    {
        p = p->rchild;
    }
    return p;
}
Node *bst::inosuc(Node *p)
{
    while (p->lchild != NULL && p != NULL)
    {
        p = p->lchild;
    }
    return p;
}
Node *bst::searchi(Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}
Node *bst::search(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    if (key < p->data)
        return search(p->lchild, key);
    else
        return search(p->rchild, key);
}
Node *bst::inserti(Node *p, int key)
{
    Node *t = NULL;
    while (p != NULL)
    {
        t = p;
        if (key < p->data)
            p = p->lchild;
        else if (key > p->data)
            p = p->rchild;
        else
            return NULL;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (t)
    {
        if (key < t->data)
            t->lchild = p;
        else
            t->rchild = p;
    }
    return p;
}
Node *bst::insert(Node *p, int key)
{
    if (p == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (key < p->data)
    {
        p->lchild = insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = insert(p->rchild, key);
    }
    return p;
}
Node *bst::Delete(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL && p->data == key)
    {
        delete (p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            Node *q = inopre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            Node *q = inosuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
int main()
{
    bst b;
    int arr[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = 8;
    Node *root = b.CreFromPreorder(arr, n);
    b.inorder(root);
    // Node *root = NULL;
    // root = b.insert(root, 30);
    // b.insert(root, 15);
    // b.insert(root, 50);
    // b.insert(root, 10);
    // b.insert(root, 20);
    // b.insert(root, 40);
    // b.insert(root, 60);

    // b.levelorder(root);
    // cout << endl;
    // b.Delete(root, 30);
    // b.levelorder(root);
    // b.inorder(root);
    // tree t1;
    // Node *root = t1.create();
    // t1.levelorder(root);
    // cout << t1.sum(root) << endl;
    // cout << t1.count_nodes(root) << endl;
    // cout << t1.count_nodes_of_degree_2(root) << endl;
    // cout << t1.height(root) << endl;
    // cout << t1.leaf_nodes(root) << endl;
    // t1.iterative_postorder(root);
    return 0;
}