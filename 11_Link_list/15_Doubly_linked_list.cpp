#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
};
class doubly_linkedlist
{
private:
    node *first = NULL;

public:
    doubly_linkedlist(int data = 0)
    {
        first = new node;
        first->data = data;
        first->prev = NULL;
        first->next = NULL;
    }
    doubly_linkedlist(int *arr, int length)
    {
        create(arr, length);
    }
    void create(int *p, int l);
    void display(void);
    int length(void);
    void insert(int index, int value);
    void Delete(int index);
    void reverse(void);
};
void doubly_linkedlist::create(int *arr, int n)
{
    first = new node;
    first->prev = NULL;
    first->data = arr[0];
    first->next = NULL;
    node *last = first;
    for (int i = 1; i < n; i++)
    {
        node *temp;
        temp = new node;
        temp->data = arr[i];
        last->next = temp;
        temp->prev = last;
        temp->next = NULL;
        last = temp;
    }
}
void doubly_linkedlist::display(void)
{
    node *t = first;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int doubly_linkedlist::length(void)
{
    int c = 0;
    node *p = first;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
void doubly_linkedlist::insert(int index, int value)
{
    if (index < 0 || index > length())
    {
        cout << "Enter a Valid Index";
        return;
    }
    node *temp = new node;
    temp->data = value;
    temp->next = temp->prev = NULL;
    if (index == 0)
    {
        first->prev = temp;
        temp->next = first;
        first = temp;
    }
    else
    {
        node *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        temp->prev = p;
        if (p->next != NULL)
        {
            p->next->prev = temp;
        }
        p->next = temp;
    }
}
void doubly_linkedlist::Delete(int index)
{
    if (index == 1)
    {
        node *p = first;
        if (first->next != NULL)
            first->next->prev = NULL;
        first = p->next;
        delete p;
    }
    else
    {
        node *p = first, *q = NULL;
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        if (p->next != NULL)
            p->next->prev = q;
        delete p;
    }
}
void doubly_linkedlist::reverse(void)
{
    node *p = first, *q;
    while (p != NULL)
    {
        q = p->next;
        p->next = p->prev;
        p->prev = q;
        if (p->prev == NULL)
        {
            first = p;
        }
        p = p->prev;
    }
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 65, 78, 98};
    doubly_linkedlist first(arr, 7);
    // cout << first.length() << endl;
    // first.insert(0, 45);
    first.display();
    // first.Delete(5);
    // first.Delete(1);
    // first.display();
    first.reverse();
    first.display();
    return 0;
}