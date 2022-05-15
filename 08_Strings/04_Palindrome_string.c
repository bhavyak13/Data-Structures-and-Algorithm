#include <stdio.h>
int main()
{
    char s[] = "madam";
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        n++;
    }
    char s1[n];
    for (int i = 0; i < n; i++)
    {
        s1[n - 1 - i] = s[i];
    }
    s1[n] = '\0';
    int t = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != s1[i])
        {
            puts("NO string is not palindrome!!");
            t = 1;
            break;
        }
    }
    if (t == 0)
    {
        puts("YES string is palindrome!!");
    }

    return 0;
}