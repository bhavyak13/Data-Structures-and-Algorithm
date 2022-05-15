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
void reverse_link(struct node *p)
{
    struct node *q = p->next, *temp = p;
    last = first;
    while (q != NULL)
    {
        p = q;
        q = q->next;
        p->next = temp;
        if (temp == first)
        {
            temp->next = NULL;
        }
        temp = p;
    }
    first = p;
}
void reverse_link1(struct node *p)
{
    struct node *q = p, *temp = NULL;
    last = first;
    while (q != NULL)
    {
        p = q;
        q = q->next;
        p->next = temp;
        temp = p;
    }
    first = p;
}
void r_R_link(struct node *p,struct node *q=NULL)
{
    if (p != NULL)
    {
        r_R_link(p->next,p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int arr[10] = {3, 3, 3, 45, 38, 3, 9};
    create(arr, 7);
    display(first);
    r_R_link(first);
    display(first);
    reverse_link1(first);
    display(first);
}