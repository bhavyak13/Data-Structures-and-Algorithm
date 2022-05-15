#include <stdio.h>
// void swaptt(int &a, int &b)
// {
//     int t = a;
//     a = b;
//     b = t;
// }

void perm(char s[], int l, int h)
{
    int i;
    if (l == h)
    {
        puts(s);
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            // swaptt(s[l], s[i]);
            int t = s[l];
            s[l] = s[i];
            s[i] = t;
            perm(s, l + 1, h);
            // swaptt(s[l], s[i]);
            t = s[l];
            s[l] = s[i];
            s[i] = t;
        }
    }
}
int main()
{
    char s[] = "ABC";
    perm(s,0,2);
    return 0;
}