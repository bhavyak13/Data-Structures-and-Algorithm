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
    //ismai ek aur pointer bnalia jo ki point krskta hai
    // ek node ko!!
    // jaise ki int pinter point krta hai integers ko
} *first = NULL;

void create(int arr[], int size)
{
    struct node *temp, *last;
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
}
// Displaying by recurrsion
void r_display(struct node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        r_display(t->next);
    }
}
// Displaying by recursion from end!
void rr_display(struct node *t)
{
    if (t != NULL)
    {
        rr_display(t->next);
        cout << t->data << " ";
    }
}

// length->no. of nodes;


// int c = 0;
// // Calculating length using recursion using glollbal varibale!!
// void length(struct node *p)
// {
//     if (p != NULL)
//     {
//         c++;
//         length(p->next);
//     }
// }
// // Calculating length using recursion using glollbal varibale!!
int length(struct node *p)
{
    int x = 0;
    if (p)
    {
        x=length(p->next);
        return x + 1;
    }
    else
    {
        return x;
    }
}

// // Calculating length using recursion!
// int length(struct node *p)
// {
//     if (p == 0) //NULL==0
//     {
//         return 0;
//     }
//     else
//     {
//         return length(p->next) + 1;
//     }
// }
// Calculating length using iteration!!
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
int main()
{
    int arr[10] = {1, 2, 4, 5};
    create(arr, 5);
    display(first);
    cout << endl;
    r_display(first);
    cout << endl;
    rr_display(first);
    cout << endl;
    // length(first);
    // cout << c;
    cout << length(first);
    cout << endl;
    cout << Length(first);
    return 0;
}