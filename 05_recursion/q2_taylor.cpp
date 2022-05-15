#include <bits/stdc++.h>
using namespace std;

// Talyor Series!!
double tal(int x, int n)
{
    static double f = 1, p = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = tal(x, n - 1);
        f *= n;
        p *= x;
        return r + p / f;
    }
}

// More Effective Method!!
double tal_short(int x, int n)
{
    static int r = n;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        double t = tal_short(x, n - 1);
        double f = (t * x / r);
        r--;
        return f + 1;
    }
}

// Using Loops!!(of effective method)
double e2(int x, int n)
{
    double r = 1;
    while (n > 0)
    {
        r /= n;
        r *= x;
        r++;
        // r = 1 + x / n * r;  //or
        n--;
    }
    return r;
}

// Effective method usong tail recursion(calling only in ascending phase!!)
double e3(int x, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    // r = (1 + (x / n) * r);
    s = 1 + x * s / n;
    return e3(x, n - 1);
}

int main()
{
    cout << tal(1, 10) << endl;
    cout << tal_short(1, 10) << endl;
    cout << e2(1, 10) << endl;
    printf("%f \n", e3(2, 10));
    return 0;
}