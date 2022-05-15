#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void create(int arr[], int size)
{
    struct node *temp;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < size; i++)
    {
        temp = new node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int Length(struct node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
void insert(int index, int value)
{
    struct node *p = first;
    if (index < 0 || index > Length(p))
    {
        puts("Index Invalid");
        return;
    }
    struct node *temp = new node;
    if (index == 0)
    {
        temp->data = value;
        temp->next = p;
        first = temp;
    }
    else if (index > 0)
    {
        // for (int i = 1; i != index && p!=NULL; i++)
        // or
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->data = value;
        temp->next = p->next;
        p->next = temp;
    }
}
void append(int value)
//inserts the elemnt at the end of the linked list!!
{
    struct node *t = new node;
    t->data = value;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void in_sorted(int value)
{
    struct node *p = first;
    struct node *t = new node;
    t->data = value;
    t->next = NULL;
    if (value < p->data)
    {
        t->next = first;
        first = t;
    }
    else
    {
        struct node *q = p;
        while ((p->data < value) && p)
        {
            q = p;
            p = p->next;
        }
        t->next = q->next;
        q->next = t;
    }
}
void Delete(int index)
{
    int x=-1;
    struct node *p = first, *q = p;
    if (index == 1)
    {
        x=first->data;
        first = first->next;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if(!p){
            return;
        }
        q->next = p->next;
        x=p->data;
        delete p;
    }
}

int main()
{
    int arr[10] = {1, 2, 4, 5, 10};
    create(arr, 5);
    display(first);
    in_sorted(7);
    display(first);
    Delete(6);
    display(first);
}