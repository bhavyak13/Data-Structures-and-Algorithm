#include <bits/stdc++.h>
using namespace std;

// a -> current position of disc //source
// c -> position of disc after moving //destination
// b -> disc used in btw //medium
void toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        cout << "from " << a << " to " << c << endl;
        toh(n - 1, b, a, c);
    }
}

int main()
{
    toh(3,1,2,3);
    return 0;
}