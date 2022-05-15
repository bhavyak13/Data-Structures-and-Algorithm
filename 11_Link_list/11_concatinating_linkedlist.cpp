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
void append(struct node *p, struct node *q)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}
int main()
{
    struct node *first1 = NULL, *first = NULL;
    int arr[10] = {31, 3, 3, 45, 38, 3, 9};
    first = create(arr, 7, first);
    display(first);
    int arr1[10] = {90, 3, 3, 45, 38, 3, 9};
    first1 = create(arr1, 7, first1);
    display(first1);
    append(first, first1);
    display(first);
}