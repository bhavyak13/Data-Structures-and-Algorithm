#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

struct term
{
    int coef;
    int expo;
};
struct polynomial
{
    int n;
    struct term *t;
};
void create(struct polynomial &p)
{
    p.t = new term[p.n];
    for (int i = 0; i < p.n; i++)
    {
        cout << ("Term no. ") << i + 1 << endl;
        cout << "Enter coefficient : ";
        cin >> p.t[i].coef;
        cout << "Enter exponent : ";
        cin >> p.t[i].expo;
    }
}

int evaluation(struct polynomial *p, int x)
{
    int ans = 0;
    for (int i = 0; i < p->n; i++)
    {
        ans += (p->t[i].coef * pow(x, p->t[i].expo));
    }
    return ans;
}
struct polynomial *addition(struct polynomial &p, struct polynomial &p1)
{
    struct polynomial *p3;
    p3->n = p1.n + p.n;
    p3->t = new term[p3->n];
    int i = 0, j = 0, k = 0;
    while (i < p.n && j < p1.n)
    {
        if (p.t[i].expo == p1.t[j].expo)
        {
            p3->t[k] = p1.t[j++];
            p3->t[k++].coef += p.t[i++].coef;
        }
        else if (p.t[i].expo > p1.t[j].expo)
        {
            p3->t[k++] = p.t[i++];
        }
        // else if (p.t[i].expo < p1.t[j].expo)
        else
        {
            p3->t[k++] = p1.t[j++];
        }
    }
    while (i < p.n)
    {
        p3->t[k++] = p.t[i++];
    }
    while (j < p1.n)
    {
        p3->t[k++] = p1.t[j++];
    }
    cout << evaluation(p3, 2);
    return p3;
}
int main()
{
    struct polynomial p1, p2, *p3;
    cout << "Enter The no. of terms in polynomial : ";
    cin >> p1.n;
    create(p1);
    int x;
    cout << "Enter the value of variable : ";
    cin >> x;
    cout << evaluation(&p1, x);

    cout << "Enter The no. of terms in polynomial : ";
    cin >> p2.n;
    create(p2);
    int y;
    cout << "Enter the value of variable : ";
    cin >> y;
    cout << evaluation(&p2, y);

    p3 = addition(p1, p2);
    int z;
    cout << "Enter the value of variable : ";
    cin >> z;
    cout << evaluation(p3, z);

    delete[] p1.t;
    p1.t = NULL;
    delete[] p2.t;
    p2.t = NULL;
    delete[] p3->t;
    p3->t = NULL;
    return 0;
}