#include <bits/stdc++.h>
using namespace std;

// Indirect Recursion!!
void B(int y);

void A(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        B(n - 1);
    }
}

void B(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        A(n / 2);
    }
}

int main()
{
    A(20);
    return 0;
}