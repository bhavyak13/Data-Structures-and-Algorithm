#include <bits/stdc++.h>
using namespace std;

double ncr(int n, int r)
{
    if (r < 0 || r > n)
    {
        return -1;
    }
    int rf = 1, nf = 1, nrf = 1;
    for (int i = 1; i <= n; i++)
    {
        nf *= i;
        if (i == r)
        {
            rf = nf;
        }
        if (i == (n - r))
        {
            nrf = nf;
        }
    }
    double a = nf / rf;
    a /= nrf;
    return a;
}

// Calculating ncr using pascal's triangle and recursion!!
double ncr1(int n, int r)
{
    if (r ==0 || r==n)
    {
        return 1;
    }
    return ncr1(n - 1, r - 1) + ncr1(n - 1, r);
}

int main()
{
    cout << ncr1(4, 2);
    return 0;
}