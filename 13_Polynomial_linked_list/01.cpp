#include <bits/stdc++.h>
using namespace std;

struct node
{
    int coef;
    int expo;
    node *next;
};
class poly
{
private:
    int length;
    node *first = NULL;

public:
    poly(int n)
    {
        length = n;
        create();
        display();
    }
    void create(void);
    void ll(int coef, int power);
    void display(void);
    int evaluate(int x);
    // poly* add(poly &p1);
};
// poly* poly::add(poly&p1){
//     node*p=first;node*q=p1.first;
// }
void poly::ll(int c, int u)
{
    if (first == NULL)
    {
        first = new node;
        first->coef = c;
        first->expo = u;
        first->next = NULL;
    }
    else
    {
        node *p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        node *temp = new node;
        temp->expo = u;
        temp->coef = c;
        temp->next = NULL;
        p->next = temp;
    }
}
void poly::create(void)
{
    while (length--)
    {
        int c, p;
        cout << "Enter coefficient: ";
        cin >> c;
        cout << "Enter Exponent: ";
        cin >> p;
        ll(c, p);
    }
}
void poly::display(void)
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->coef << "x" << p->expo;
        if (p->next)
        {
            cout << " + ";
        }
        else
        {
            cout << endl;
        }
        p = p->next;
    }
}
int poly::evaluate(int x)
{
    node *p = first;
    int s = 0;
    while (p != NULL)
    {
        s += (pow(x, p->expo) * p->coef);
        p = p->next;
    }
    return s;
}

int main()
{
    cout << "Enter no. of Terms: ";
    int n;
    cin >> n;
    poly x1(n);
    int m;
    cout << "Enter x: ";
    cin >> m;
    cout << x1.evaluate(m);
    return 0;
}