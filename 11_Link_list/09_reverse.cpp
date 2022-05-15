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
void reverse_element(struct node *p)
{
    int n = Length(first);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }
    p = first;
    // for (int i = 0; i < n / 2; i++)
    // {
    //     swap(arr[i], arr[n - 1 - i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     p->data = arr[i];
    //     p = p->next;
    // }

    // or
    
    for (int i = n - 1; i >= 0; i--)
    {
        p->data = arr[i];
        p = p->next;
    }
}
int main()
{
    int arr[10] = {3, 3, 3, 3, 3, 3, 9};
    create(arr, 7);
    display(first);
    reverse_element(first);
    display(first);
}