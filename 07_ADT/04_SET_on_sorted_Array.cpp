#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int union_k = 0, intr_k = 0;
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
int *union1(int *a, int *b, int ni, int nb)
{
    int *r = new int[ni + nb];
    int i = 0, j = 0, k = 0;
    while ((i < ni) && (j < nb))
    {
        if (a[i] < b[j] && i < ni)
        {
            r[k++] = a[i++];
            if (a[i] == b[j])
            {
                j++;
            }
        }
        else
        {
            r[k++] = b[j++];
            if (a[i] == b[j])
            {
                i++;
            }
        }
    }
    while (i < ni)
    {
        r[k++] = a[i++];
    }
    while (j < nb)
    {
        r[k++] = b[j++];
    }
    ::union_k = k;
    return r;
}
int *intr(int *a, int *b, int ni, int nb)
{
    int *r = new int[ni + nb];
    int i = 0, j = 0, k = 0;
    while ((i < ni) || (j < nb))
    {
        if (a[i] == b[j])
        {
            r[k++] = a[i++];
            j++;
        }

        // Abdul Sir Method!!

        // else if(a[i]<b[j]){
        //     i++;
        // }
        // else{j++;}

        // MY Method!!
        // p.s. : Both are same!
        else
        {
            while (a[i] < b[j])
                i++;
            while (b[j] < a[i])
                j++;
        }
    }
    ::intr_k = k;
    return r;
}
int diff_k=0;
int *diff(int *a, int *b, int ni, int nb)
{
    // We have to Do A-B
    // i.e. print those elements of A which are not in B
    int *r = new int[ni + nb];
    int i = 0, j = 0, k = 0;
    while ((i < ni) || (j < nb))
    {
        if (a[i] < b[j])
        {
            r[k++] = a[i++];
        }
        else if(a[i]==b[j]){
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    while(i<ni){
        r[k++]=a[i++];
    }
    ::diff_k = k;
    return r;
}

int main()
{
    int n1 = 6, n2 = 6;
    // cout << "Enter Size of element : ";
    // cin >> n1;
    int arr1[n1] = {8, 99, 100, 103, 104,106};
    // cout << "Enter Elements: ";
    // initialising(n1, arr1);
    // cout << "Enter Size of element : ";
    // cin >> n2;
    int arr2[n2] = {1, 18, 98, 100, 102, 104};
    // cout << "Enter Elements: ";
    // initialising(n1, arr1);

    // int *prin = union1(arr1, arr2, n1, n2);
    // display(prin, union_k);
    // int *prin = intr(arr1, arr2, n1, n2);
    // display(prin, intr_k);
    int *prin = diff(arr1, arr2, n1, n2);
    display(prin, diff_k);
    delete[] prin;
    return 0;
}