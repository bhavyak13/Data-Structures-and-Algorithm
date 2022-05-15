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
int sum(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return p->data + sum(p->next);
}
int main()
{
    int arr[5] = {3, 4, 9, 2, 1};
    struct node *first;
    first = new node;
    create(arr, 5, first);
    cout << sum(first);
    return 0;
}