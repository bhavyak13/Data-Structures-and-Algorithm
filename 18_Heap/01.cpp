#include <bits/stdc++.h>
using namespace std;
// int arr[8] = {0, 10, 20, 30, 25, 5, 40, 35};
int arr[8] = {0, 40, 35, 30, 15, 10, 25, 5};

void insert(int index)
{
    int i = index;
    int x = arr[index];
    while (x > arr[i / 2] && i > 1)
    {
        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = x;
}
void create(int size)
{
    for (int i = 2; i <= size; i++)
        insert(i);
}

void Delete(int size)
{
    int deleted = arr[1];
    arr[1] = arr[size];
    int i = 1, j = 2 * i;
    while (j < size - 1)
    {
        if (arr[j + 1] > arr[j])
            j += 1;
        if (arr[i] < arr[j])
        {
            swap(arr[i], arr[j]);
            i = j;
            j *= 2;
        }
        else
            break;
    }
    arr[size] = deleted;
}
void heapsort()
{
    int size =7;
    for (int i =size; i >= 1; i--)
        Delete(i);
}
int main()
{
    create(7);
    // cout << endl;
    for (int i = 1; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}