#include <bits/stdc++.h>
using namespace std;

// 0 1 1 2 3 5 8 13 21 34
int fibo(int n)
{
    // if (n == 0)
    // {
    //     return 0;
    // }
    // else if (n == 1)
    // {
    //     return 1;
    // }
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

// Iterative Method!!
int fibo2(int n)
{
    int a = 0;
    int b = 1;
    int c, d = n;
    if (n <= 1)
    {
        return n;
    }
    while (n > 1)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int arr[10];
// Effective Fibo!!
int fibo3(int n)
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    if (arr[n - 2] == -1)
    {
        arr[n - 2] = fibo3(n - 2);
    }
    if (arr[n - 1] == -1)
    {
        arr[n - 1] = fibo3(n - 1);
    }
    return arr[n - 1] + arr[n - 2];
}

int main()
{
    for (int i = 0; i < 10; i++) // ...initialize it
    {
        arr[i] = -1;
    }
    cout << fibo(9) << endl;
    cout << fibo2(9) << endl;
    cout << fibo3(9) << endl;
    return 0;
}