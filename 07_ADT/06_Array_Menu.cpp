#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

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

void inserti(int index, int element, struct Array &a1)
{
    if (index > (a1.length + 1))
    {
        // In this case we will add elemnt to the last !!
        index = a1.length + 1;
    }
    else if (index < 0)
    {
        cout << "Enter a VAlid Index :)" << endl;
        return;
    }
    for (int i = a1.length; i > index; i--)
    {
        a1.ptr[i] = a1.ptr[i - 1];
    }
    a1.ptr[index] = element;
    a1.length++;
}

void deletei(int index, struct Array &a1)
{
    for (int i = index; i < a1.length - 1; i++)
    {
        a1.ptr[i] = a1.ptr[i + 1];
    }
    a1.length--;
}

int linear_search(int value, struct Array &arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (value == arr.ptr[i])
        {
            return i;
        }
    }
    return -1;
}

// using loops!!
int binary_search(int key, struct Array &arr)
{
    int l = 0, h = arr.length - 1, m;
    while (l <= h)
    {
        int m = ceil((l + h) / 2);
        if (arr.ptr[m] == key)
        {
            return m;
        }
        else if (key > arr.ptr[m])
        {
            l = m + 1;
        }
        else
        //  (key < arr.ptr[m])
        {
            h = m - 1;
        }
    }
    return -1;
}

// binary seach using recurrsion!!
int binary_search_r(int key, int l, int h, struct Array &ar)
{
    int mid = ceil((l + h) / 2);
    if (l <= h)
    {
        if (ar.ptr[mid] == key)
        {
            return mid;
        }
        else if (key > ar.ptr[mid])
        {
            return binary_search_r(key, mid + 1, h, ar);
        }
        else
        {
            return binary_search_r(key, l, mid - 1, ar);
        }
    }
    else
    {
        return -1;
    }
}

int get(int index, struct Array &a1)
{
    if (index >= 0 && index < a1.length)
        return a1.ptr[index];
    return -1;
}

void set(int index, int key, struct Array &a1)
{
    if (index >= 0 && index < a1.length)
        a1.ptr[index] = key;
}

int maxo(struct Array &a1)
{
    int t = a1.ptr[0];
    for (int i = 1; i < a1.length; i++)
    {
        if (a1.ptr[i] > t)
        {
            t = a1.ptr[i];
        }
    }
    return t;
}

int mino(int index, struct Array &a1)
{
    int t = a1.ptr[0];
    for (int i = 1; i < a1.length; i++)
    {
        if (a1.ptr[i] < t)
        {
            t = a1.ptr[i];
        }
    }
    return t;
}

int sum(struct Array &a1)
{
    int sum = 0;
    for (int i = 0; i < a1.length; i++)
    {
        sum += a1.ptr[i];
    }
    return sum;
}
// Sum using Recursion
int sum_r(int n, struct Array &arr)
{
    // n->length of array!!
    if (n > 0)
    {
        return arr.ptr[n - 1] + sum_r(n - 1, arr);
    }
    return 0;
}

double avg(struct Array &a1)
{
    int sum = 0;
    for (int i = 0; i < a1.length; i++)
    {
        sum += a1.ptr[i];
    }
    return sum / (a1.length);
}

void reverse_1(int n, int *p)
{
    // Here p is pointer to the First element of an array
    for (int i = 0; i < floor(n / 2); i++)
    {
        swap(p[i], p[n - 1 - i]);
    }
}

int *reverse_2(int n, int *p)
{
    // Here p is pointer to the First element of an array
    // 1 2 3 4 5 6
    // 0 1 2 3 4 5
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = p[n - 1 - i];
    }
    delete[] p;
    p = arr;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }
    return p;
}

void left_shift(int n, int *p)
{
    for (int i = 0; i < n - 1; i++)
    {
        p[i] = p[i + 1];
    }
    p[n - 1] = 0;
}

void right_shift(int n, int *p)
{
    for (int i = n - 1; i > 0; i--)
    {
        p[i] = p[i - 1];
    }
    p[0] = 0;
}

void left_rotate(int n, int *p)
{
    int x = p[0];
    for (int i = 0; i < n - 1; i++)
    {
        p[i] = p[i + 1];
    }
    p[n - 1] = x;
}

void right_rotate(int n, int *p)
{
    int x = p[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        p[i] = p[i - 1];
    }
    p[0] = x;
}

// File 2
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

// File 3
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
// File 4
int union_k = 0, intr_k = 0, diff_k=0;
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
    struct Array arr;

    // Extras ->
    delete[] arr.ptr;
    arr.ptr = NULL;
    return 0;
}
    // cout << "Enter Size Of Array : ";
    // cin >> arr.size;
    // arr.ptr = new int[arr.size];
    // cout << "Enter No. of ELements : ";
    // cin >> arr.length;
    // initialising(arr.length, arr);
    // display(arr);
    // // inserti(4, 15, arr);
    // // // display(arr);
    // // deletei(2, arr);
    // // display(arr);
    // // cout << linear_search(64, arr) << endl;
    // cout << binary_search_r(41, 0, arr.length, arr) << endl;
    // // cout<<"Sum of all Elements : "<<sum_r(arr.length,arr);
    // // arr.ptr = reverse_2(arr.length, arr.ptr);
    // // right_rotate(arr.length, arr.ptr);
    // display(arr);
