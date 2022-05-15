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
};

struct node *create(int arr[], int size, struct node *first)
{
    struct node *temp, *last = NULL;
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
    return first;
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
struct node *merge(struct node *p, struct node *q)
{
    struct node *f = NULL, *l = NULL;
    // int arr[10] = {31, 32, 33, 45, 67, 93, 98};
    // int arr1[10] = {1, 2, 3, 4, 5, 94, 99};
    if (q->data < p->data)
    {
        f = q;
        l = q;
        q = q->next;
        l->next = NULL;
    }
    else
    {
        f = p;
        l = p;
        p = p->next;
        l->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            l->next = p;
            l = p;
            p = p->next;
            l->next = NULL;
        }
        else
        // else if (q->data < p->data)
        {
            l->next = q;
            l = q;
            q = q->next;
            l->next = NULL;
        }
    }
    if (p != NULL)
    {
        l->next = p;
    }
    else
    {
        l->next = q;
    }
    return f;
}
void Delete(struct node *p){
    struct node *t=p;
    while(t!=NULL){
        p=p->next;
        delete t;
        t=p;
    }
}
int main()
{
    struct node *first1 = NULL, *first = NULL;
    int arr[10] = {31, 32, 33, 45, 67, 93, 98};
    first = create(arr, 7, first);
    display(first);
    display(first);
    int arr1[10] = {1, 2, 3, 4, 5, 94, 99};
    first1 = create(arr1, 7, first1);
    display(first1);
    struct node *d = merge(first, first1);
    display(d);
    Delete(d);
}