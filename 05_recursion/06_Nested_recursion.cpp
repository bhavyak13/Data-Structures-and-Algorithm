#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else
    {
        return f(f(n + 11));
    }
}

int main()
{
    cout << f(95);
    return 0;
}