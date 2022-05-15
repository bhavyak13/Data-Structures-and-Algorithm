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
bool issorted(struct node *p)
{
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
        {
            return false;
        }
        p = p->next;
    }
    return true;
}
int main()
{
    int arr[10] = {1, 2, 4, 5, 1};
    create(arr, 5);
    display(first);
    cout << issorted(first);
    //0->false anyother->true
}