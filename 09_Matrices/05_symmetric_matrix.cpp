#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

class Matrix
{
private:
    int size;
    int *arr;

public:
    Matrix(int size)
    {
        this->size = size;
        arr = new int[(size * (size + 1) / 2)];
    }
    void set(int x, int y, int value);
    int get(int x, int y);
    void setall(void);
    void display(void);
    ~Matrix(void)
    {
        delete[] arr;
        arr = NULL;
    }
};
void Matrix::set(int x, int y, int value)
{

    int t = size * (y - 1) - ((y - 1) * (y - 2) / 2);
    t += x - y;
    arr[t] = value;
}
int Matrix::get(int x, int y)
{
    if (x >= y)
    {
        int t = x * (x - 1) / 2;
        t += (y - 1);
        return arr[t];
    }
    else
    {
        return 0;
    }
}
// USing Row MAjor!!
void Matrix::display(void)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (i >= j)
            {
                int x = i * (i - 1) / 2;
                x += (j - 1);
                cout << arr[x] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}
void Matrix::setall(void)
{
    for (int i = 0; i < size * (size + 1) / 2; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    cout << "Enter Dimensions: ";
    int m;
    cin >> m;
    Matrix m1(m);
    cout << "Enter all Non-Zero Elements Of Lower Triangluar Matrix" << endl;
    m1.setall();
    m1.display();
    cout << m1.get(4, 4) << endl;
    cout << m1.get(1, 4) << endl;
    cout << m1.get(3, 3) << endl;
    return 0;
}