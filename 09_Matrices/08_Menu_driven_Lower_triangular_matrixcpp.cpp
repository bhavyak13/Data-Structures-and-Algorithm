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
    A = new int[n * (n + 1) / 2];
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
        int t = 0;
        int i, j, value;
        switch (ch)
        {
        // 1. Create.
        case 1:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> x;
                    if (x != 0)
                    {
                        A[t] = x;
                        t++;
                    }
                }
            }
            t = 0;
            break;

        case 2:
            cout << "Enter row number : ";
            cin >> i;
            cout << "Enter Column number : ";
            cin >> j;
            if (i >= j)
            {
                int v = i * (i - 1) / 2;
                v += (j - 1);
                cout << A[v];
            }
            else
            {
                cout << 0;
            }
            cout << endl;
            break;
        case 3:
            // Set
            cout << "Enter row number : ";
            cin >> i;
            cout << "Enter Column number : ";
            cin >> j;
            cout << "Enter Value : ";
            cin >> value;
            if (i >= j)
            {
                A[i * (i - 1) / 2 + j - 1] = value;
            }
            break;
        case 4:
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i >= j)
                    {
                        cout << A[i * (i - 1) / 2 + j - 1] << " ";
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