#include <bits/stdc++.h>
using namespace std;

void func(int n)
{
    if (n > 0)
    {
        func(n - 1);
        cout << n << endl;
    }
}

void func1(int n)
{
    int i = 1;
    while (i <= n)
    {
        cout << i << endl;
        i++;
    }
}

int main()
{
    func(3);
    func1(3);
    return 0;
}