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
void remove_duplicate(struct node *p)
{
    struct node *q = p;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            q = p->next->next;
            delete p->next;
            p->next = q;
        }
        else
        {
            p = p->next;
        }
    }
}
// AB sirs Method!!
// void remove_duplicate(struct node *p)
// {
//     struct node *q = p->next;
//     while (q != NULL)
//     {
//         if (q->data == p->data)
//         {
//             q = q->next;
//             delete p->next;
//             p->next = q;
//         }
//         else
//         {
//             p = q;
//             q = q->next;
//         }
//     }
// }
int main()
{
    int arr[10] = {3, 3, 3, 3, 3, 3,9};
    create(arr, 7);
    display(first);
    remove_duplicate(first);
    display(first);
}