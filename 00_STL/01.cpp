#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vector<int>::iterator x = lower_bound(vec.begin(), vec.end() - 1, 10);
    cout << *x << endl;
    cout <<"Position : "<< distance(vec.begin(), x)+1;
    return 0;
}