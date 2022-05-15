#include <bits/stdc++.h>
using namespace std;
int expo(int n, int m)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return m * expo(n - 1, m);
    }
}
int expo1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            return expo1(m * m, n / 2);
        }
        else
        {
            return m * expo1(m * m, (n) / 2);
        }
    }
}
int main()
{
    cout << expo(2, 8) << endl;
    cout << expo1(6, 3);
    return 0;
}