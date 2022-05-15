#include <bits/stdc++.h>
#define SIZE 10
using namespace std;

int H[SIZE] = {};
int hashfunction(int key)
{
    return (key % SIZE);
}
int probe(int key)
{
    int x = hashfunction(key);
    int i = 0;
    while (((H[x + i]) % SIZE) != 0)
    {
        i++;
    }
    return (x + i) % SIZE;
}

int probes(int key)
{
    int index = hashfunction(key);
    int i = 1;
    while (key != H[(index + i) % SIZE])
    {
        if (!H[(index + i) % SIZE])
            return -1;
        i++;
    }
    return (index + i) % SIZE;
}

int search(int key)
{
    int index = hashfunction(key);
    if (key == H[index])
        return H[index];
    int x = probes(key);
    if (x == -1)
        return x;
    return H[x];
}
void insert(int key)
{
    int x = hashfunction(key);
    if (H[x] == 0)
    {
        H[x] = key;
        return;
    }
    H[probe(x)] = key;
    return;
}
int main()
{
    int arr[5] = {25, 30, 23, 24, 43};

    for (int i = 0; i < 5; i++)
    {
        insert(arr[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << H[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << search(arr[i]) << " ";
    }
    cout << search(53) << " ";

    return 0;
}