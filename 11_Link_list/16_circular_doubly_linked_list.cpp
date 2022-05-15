#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *prev;
    node *next;
    int data;
};

class CDLL
{
private:
    node *head;
    int length;

public:
    CDLL(int *arr, int length)
    {
        this->length = length;
        create(arr, length);
    }
    void create(int *arr, int length);
    void display(void);
    void insert(int index, int value);
    int Delete(int index);
};
void CDLL::create(int *arr, int length)
{
    head = new node;
    head->data = arr[0];
    head->next = head->prev = head;
    node *last = head;
    for (int i = 1; i < length; i++)
    {
        node *temp = new node;
        temp->data = arr[i];
        temp->prev = last;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    head->prev = last;
}
void CDLL::display(void)
{
    node *p = head;
    cout << "DISPLAYING ELEMENTS!!\n";
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}
void CDLL::insert(int index, int value)
{
    if (index < 0 || index > length)
    {
        cout << "Enter Valid Index!!\n";
        return;
    }
    node *p = head;
    node *temp = new node;
    temp->data = value;
    if (index == 0)
    {
        head->prev->next = temp;
        temp->prev = head->prev;
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
        temp->prev = p;
    }
}
int CDLL::Delete(int index)
{
    int x=-1;
    if (index < 0 || index > length)
    {
        return x;
    }
    node *p = head;
    if (index == 1)
    {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = p->next;
        x=p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x=p->data;
        delete p;
    }
    return x;
}

int main()
{
    int arr[10] = {31, 32, 33, 45, 67, 93, 98};
    CDLL head(arr, 7);
    head.display();
    // head.insert(10, 8);
    head.Delete(7);
    head.display();
    return 0;
}