#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    int *A, n, ch, x;
    cout << "Enter Dimensions : ";
    cin >> n;
    A = new int[n];
    do
    {
        cout << endl;
        cout << "Menu:\n";
        puts("1. Create.");
        puts("2. Get a specific Index.");
        puts("3. Set a specific Index some value.");
        puts("4. Display.");
        puts("5. Exit.");
        cout << "Enter your choise: ";
        cin >> ch;
        cout << endl;
        int i, j, value;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cin >> A[i];
            }
            break;

        case 2:
            cout << "Enter row number : ";
            cin >> i;
            cout << "Enter Column number : ";
            cin >> j;
            if (i == j)
            {
                cout << A[i - 1];
            }
            else
            {
                cout << 0;
            }
            cout << endl;
            break;
        case 3:
            cout << "Enter row number : ";
            cin >> i;
            cout << "Enter Column number : ";
            cin >> j;
            cout << "Enter Value : ";
            cin >> value;
            if (i == j)
            {
                A[i - 1] = value;
            }
            break;
        case 4:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
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
                cout << "\n";
            }
        default:
            break;
        }
    } while (ch != 5);

    return 0;
}