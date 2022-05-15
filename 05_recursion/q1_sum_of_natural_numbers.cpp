#include <bits/stdc++.h>
using namespace std;

int sumi(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return (n + sumi(n - 1));
}

int main()
{
    int a;
    cin >> a;
    cout << sumi(a);
    return 0;
}