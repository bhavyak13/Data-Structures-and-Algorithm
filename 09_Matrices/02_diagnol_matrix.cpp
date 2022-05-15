#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

class matrix
{
private:
    int size;
    int *A;

public:
    matrix(int n)
    {
        size = n;
        A = new int[n];
    }
    void set(int x, int y, int value)
    {
        if (x == y)
        {
            A[x - 1] = value;
        }
    }
    int get(int x, int y)
    {
        if (x == y)
        {
            return A[x - 1];
        }
        return 0;
    }
    void display(void)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    cout << A[i] << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
    ~matrix(void)
    {
        delete[] A;
        A = NULL;
    }
} m1(4);

int main()
{
    m1.set(1, 1, 4);
    m1.set(2, 2, 9);
    m1.set(3, 3, 7);
    m1.set(4, 4, 6);
    m1.display();
    cout << m1.get(4, 4);
    return 0;
}