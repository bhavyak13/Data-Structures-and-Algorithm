#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *H[10] = {NULL};
int hashFunction(int n)
{
    return n % 10;
}

void sortedInsert(int key)
{

    int index = hashFunction(key);
    node *t;
    if (H[index] == NULL)
    {
        t = new node;
        t->data = key;
        t->next = NULL;
        H[index] = t;
        return;
    }
    t = H[index];
    node *p = t;
    while (t != NULL && t->data < key)
    {
        p = t;
        t = t->next;
    }
    node *q = new node;
    q->data = key;
    q->next = t;
    p->next = q;
}
node *search(int key)
{
    int index = hashFunction(key);
    // if (!H[index])
    //     return NULL;
    node *t = H[index], *p;
    p = t;
    while (t)
    {
        if (t->data == key)
            return t;
        else if (t->data > key)
            return NULL;
        t = t->next;
    }
    return NULL;
}
int main()
{
    sortedInsert(4);
    sortedInsert(5);
    sortedInsert(15);
    sortedInsert(25);
    node *x = search(40);
    if (x)
        cout << x->data << " ";
    else
        cout << "NOt found";
    for (int i = 0; i < 10; i++)
        cout << H[i] << " ";

    return 0;
}