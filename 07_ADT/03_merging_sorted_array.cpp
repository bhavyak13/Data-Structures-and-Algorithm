#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int *merge(int *a, int *b, int ni, int nb)
{
    int *r = new int[ni + nb];
    int i = 0, j = 0, k = 0;
    while ((i < ni) && (j < nb))
    {
        if (a[i] < b[j] && i < ni)
        {
            r[k++] = a[i++];
        }
        else
        {
            r[k++] = b[j++];
        }
    }
    while(i<ni){
        r[k++]=a[i++];
    }
    while(j<nb){
        r[k++]=b[j++];
    }
    return r;
}
void initialising(int l, int *p)
{
    for (int i = 0; i < l; i++)
    {
        cin >> p[i];
    }
}
void display(int *p, int l)
{
    cout << "DISPAYING ELEMNTS \n";
    for (int i = 0; i < l; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n1 = 5, n2 = 6;
    // cout << "Enter Size of element : ";
    // cin >> n1;
    int arr1[5] = {8, 9, 10, 45, 65468};
    // cout << "Enter Elements: ";
    // initialising(n1, arr1);
    // cout << "Enter Size of element : ";
    // cin >> n2;
    int arr2[6] = {1,18, 988, 1000, 1002, 10004};
    // cout << "Enter Elements: ";
    // initialising(n1, arr1);
    int *prin = merge(arr1, arr2, n1, n2);
    display(prin, (n1 + n2));
    delete[] prin;
    return 0;
}