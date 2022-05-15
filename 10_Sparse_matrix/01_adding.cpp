#include <bits/stdc++.h>
using namespace std;

struct element
{
    int row;
    int col;
    int value;
};

struct sparse
{
    int m_row;
    int m_col;
    int n;               //n->no. of non zero elements!
    struct element *ptr; //Doubt: why is this pointer?
};
void create(struct sparse &s)
{
    puts("Enter Dimensions!!");
    cout << "No. of rows: ";
    cin >> s.m_row;
    cout << "No. of Columns: ";
    cin >> s.m_col;
    cout << "Enter no. of Non Zero Elements: ";
    cin >> s.n;
    s.ptr = new element[s.n]; // Creating s.n number of structs(naming: element)// i.e. n number of structures will bwe created
    for (int i = 0; i < s.n; i++)
    {
        cout << "Row number : ";
        cin >> s.ptr[i].row;
        cout << "Column Number : ";
        cin >> s.ptr[i].col;
        cout << "Value : ";
        cin >> s.ptr[i].value;
        cout << "\n";
    }
}
void display(struct sparse &s)
{
    int k = 0;
    puts("Displaying Matrix: ");
    for (int i = 1; i <= s.m_row; i++)
    {
        for (int j = 1; j <= s.m_col; j++)
        {
            if (s.ptr[k].row == i && s.ptr[k].col == j)
            {
                cout << s.ptr[k++].value << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
    }
    cout << "\n";
}
void add(struct sparse &s1, struct sparse &s2)
{
    if (s1.m_col != s2.m_col || s1.m_row != s2.m_row)
    {
        puts("Addition is not pomsible ssssomry darling :)");
        return;
    }
    struct sparse s3;
    s3.m_row = s1.m_row;
    s3.m_col = s1.m_col;
    s3.n = s1.n + s2.n;
    s3.ptr = new element[s3.n];
    int i = 0, j = 0, k = 0;
    while (i < s1.n && j < s2.n)
    {
        if (s1.ptr[i].row < s2.ptr[j].row)
        {
            s3.ptr[k].row = s1.ptr[i].row;
            s3.ptr[k].col = s1.ptr[i].col;
            s3.ptr[k++].value = s1.ptr[i++].value;
        }
        else if (s1.ptr[i].row > s2.ptr[j].row)
        {
            s3.ptr[k++] = s2.ptr[j++];
        }
        // else if (s1.ptr[i].row == s2.ptr[j].row)
        else
        {
            if (s1.ptr[i].col < s2.ptr[j].col)
            {
                s3.ptr[k++] = s1.ptr[i++];
            }
            else if (s1.ptr[i].col > s2.ptr[j].col)
            {
                s3.ptr[k++] = s2.ptr[j++];
            }
            else
            {
                s3.ptr[k].row = s1.ptr[i].row;
                s3.ptr[k].col = s1.ptr[i].col;
                s3.ptr[k++].value = s1.ptr[i++].value + s2.ptr[j++].value;
            }
        }
    }
    display(s3);
}
int main()
{
    struct sparse s1, s2;
    create(s1);
    display(s1);
    create(s2);
    display(s2);
    add(s1, s2);
    return 0;
}