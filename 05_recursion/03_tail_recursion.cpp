#include <bits/stdc++.h>
using namespace std;

void func(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        func(n - 1);
    }
}

void func1(int n)
{
    while (n > 0)
    {
        cout << n << endl;
        n--;
    }
}
/*
Tail Recursion can be easily converted into loops!!
and loops are more effective in comparision of tail recursion
as 
recursion has 2 phases : ascending and descending!!
but as in case of tail recursion only ascending phase will perform operations
and no operation is performed during descending phase!!
hence now will compare:
loops are more effective in this case as space complexity
of tail recursion in this case will be 4 i.e. O(n)!!
where as when same code is writen in loops
space complexity will be of O(1)!!
*/
int main()
{
    func(3);
    func1(3);
    return 0;
}

