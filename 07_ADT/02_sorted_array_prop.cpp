#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

struct Array
{
    int length;
    int size;
    int *ptr;
};

void initialising(int l, struct Array &a1)
{
    for (int i = 0; i < l; i++)
    {
        cin >> a1.ptr[i];
    }
}

void display(struct Array &arrr)
{
    cout << "DISPAYING ELEMNTS \n";
    for (int i = 0; i < arrr.length; i++)
    {
        cout << arrr.ptr[i] << " ";
    }
    cout << endl;
}

// Given that array is sorted
// Insertion in sorted array function!
// Shifting to hogi he !!
void insert_s(int value, struct Array &a1)
{
    int i;
    // OP!!
    for (i = a1.length - 1; a1.ptr[i] > value; i--)
    {
        a1.ptr[i + 1] = a1.ptr[i];
    }
    a1.ptr[i + 1] = value;
    a1.length++;
}
bool issorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.ptr[i] > arr.ptr[i + 1])
        {
            return false; //0
        }
    }
    return true; //1
}
void separte_negative_positive(struct Array &arr)
{
    int i = 0, j = arr.length - 1;
    while (i < j)
    {
        while (arr.ptr[i] < 0)
        {
            i++;
        }
        while (arr.ptr[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr.ptr[i], arr.ptr[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    int x;
    struct Array arr;
    cout << "Enter Size Of Array : ";
    cin >> arr.size;
    arr.ptr = new int[arr.size];
    cout << "Enter No. of ELements : ";
    cin >> arr.length;
    initialising(arr.length, arr);
    display(arr);
    // cout << "Enter The Element you wanna insert: ";
    // cin >> x;
    // insert_s(x, arr);
    // display(arr);
    // cout << issorted(arr);
    separte_negative_positive(arr);
    display(arr);
    return 0;
}