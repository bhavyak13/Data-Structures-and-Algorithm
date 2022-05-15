#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int col;
    int val;
    node *next;
};
class sparse
{
private:
    int m, n;
    // node **arr;
    node *arr[5] = {NULL, NULL, NULL, NULL, NULL};

public:
    sparse(int m, int n)
    {
        this->m = m;
        this->n = n;
        // node *arr = new node[5]{NULL, NULL, NULL, NULL, NULL};
        // this->arr = &arr;
    }
    void create(int x);
    void display(void);
    void ll(int r, int c, int value);
    void add(void);
};

void sparse::ll(int r, int c, int value)
{
    if (arr[r] == NULL)
    {
        node *temp = new node;
        temp->col = c;
        temp->val = value;
        temp->next = NULL;
        arr[r] = temp;
    }
    else
    {
        node *t = arr[r];
        while (t->next != NULL)
        {
            t = t->next;
        }
        node *temp = new node;
        temp->col = c;
        temp->val = value;
        temp->next = NULL;
        t->next = temp;
    }
}
void sparse::create(int x)
{
    int r, c, w;
    while (x--)
    {
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter Column number: ";
        cin >> c;
        cout << "Enter Value: ";
        cin >> w;
        ll(r - 1, c - 1, w);
    }
}
void sparse::display(void)
{
    for (int i = 0; i < m; i++)
    {
        node *p = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (p != NULL && j == p->col)
            {
                cout << p->val << " ";
                p = p->next;
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    sparse h(5, 6);
    int x;
    puts("Enter number of Non-zero Elements: ");
    cin >> x;
    h.create(x);
    h.display();
    return 0;
}