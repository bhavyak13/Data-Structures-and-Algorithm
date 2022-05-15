#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create(int arr[], int size, struct node *head)
{
    struct node *temp, *last = NULL;
    head = new node;
    head->data = arr[0];
    head->next = head;
    last = head;
    for (int i = 1; i < size; i++)
    {
        temp = new node;
        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    return head;
}
void display(struct node *p)
{
    cout << "DISPLAYING ELEMENTS!!\n";
    struct node *o = p;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (o != p);
    cout << endl;
}
void r_display(struct node *p, struct node *head)
{
    static int flag = 0;
    if (flag == 0 || p != head)
    {
        flag = 1;
        cout << p->data << " ";
        r_display(p->next, head);
    }
    flag = 0;
}
bool isloop(struct node *f)
{
    struct node *p = f, *q = f;
    do
    {
        p = p->next;
        q = q->next;
        if (q == NULL)
        {
            return false;
        }
        q = q->next;
    } while (q && p && p != q);
    if (p == q)
    {
        return true;
    }
    return false;
}
void inserti(struct node *p, struct node *head, int value)
{
    struct node *temp = new node;
    temp->data = value;
    if (p == head)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct node *t = head, *q = NULL;
        do //8:36
        {
            q = t;
            t = t->next;
        } while (t != p);
        q->next = temp;
        temp->next = t;
    }
}
struct node *insert(int index, int value, struct node *head)
{
    struct node *temp = new node;
    temp->data = value;
    if (index == 0)
    {
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            temp->next = head;
            struct node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            head = temp;
            last->next = temp;
        }
        return head;
    }
    else
    {
        struct node *q = head;
        for (int i = 1; i < index; i++)
        {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
        return head;
    }
}
struct node *Delete(int index, struct node *head)
{
    struct node *t = head;
    if (index == 1)
    {
        while (t->next != head)
        {
            t = t->next;
        }
        head = head->next;
        delete t->next;
        t->next = head;
    }
    else
    {
        struct node *q = head;
        for (int i = 1; i < index; i++)
        {
            q = t;
            t = t->next;
        }
        q->next = t->next;
        delete t;
    }
    return head;
}
int main()
{
    struct node *first1 = NULL, *first = NULL;
    int arr[10] = {31, 32, 33, 45, 67, 93, 98};
    first = create(arr, 7, first);
    first = insert(7, 222, first);
    first = Delete(3, first);
    r_display(first, first);
}
