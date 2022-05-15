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
struct node *first;
void create(int arr[], int size, struct node *p)
{
    struct node *temp, *last;
    last = p;
    p->data = arr[0];
    p->next = NULL;
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
    if (p != 0)
    {
        cout << p->data << " ";
        display(p->next);
    }
}

int Max(struct node *p)
{
    int max = p->data;
    p = p->next;
    for (int i = 1; p; i++)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
// My Method:
int r_Max(struct node *p)
{
    static int max = INT_MIN;
    if (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        r_Max(p->next);
    }
    return max;
}
// AB Sir Method:
int r_ab_Max(struct node *p)
{
    int x;
    if (p == NULL)
    {
        return INT_MIN;
    }
    x = r_ab_Max(p->next);
    return (x > p->data) ? x : p->data;
}
struct node *linear_search(struct node *p, int key)
{
    while (p->data != key)
    {
        p = p->next;
        return p;
    }
    return NULL;
}
struct node *r_linear_search(struct node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data == key)
    {
        return p;
    }
    return r_linear_search(p->next, key);
}
struct node *i_linear_search(struct node *p, int key)
{

    struct node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            // cout<<first->data;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
int length(struct node *p)
{
    if (p != NULL)
    {
        return 1 + length(p->next);
    }
    return 0;
}
void insert(int index, int value)
{
    struct node *p = first;
    if (index < 0 || index > length(p))
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
int main()
{
    first = new node;
    int arr[5] = {3, 4, 9, 2, 1};
    create(arr, 5, first);
    display(first);
    cout << endl;
    cout << r_Max(first) << endl;
    cout << r_ab_Max(first) << endl;
    // struct node *temp = r_linear_search(first, 9);
    // cout << temp->data << endl;
    cout << r_linear_search(first, 9) << endl;
    // i_linear_search(first, 9);
    // i_linear_search(first, 1);
    // display(first);
    // cout<<first->data;
    insert(0, 98);
    display(first);
    insert(90, 78);
    display(first);
    return 0;
}