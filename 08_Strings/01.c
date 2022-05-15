#include <stdio.h>
#include <stdlib.h>
// Calculating Length
int get_length(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
// changing Case
void change_case(char *s1)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] >= 65 && s1[i] <= 90)
        {
            s1[i] += 32;
        }
        else if (s1[i] >= 97 && s1[i] <= 122)
        {
            s1[i] -= 32;
        }
    }
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] >= 65 && s1[i] <= 90)
        {
            s1[i] += 32;
        }
        else if (s1[i] >= 97 && s1[i] <= 122)
        {
            s1[i] -= 32;
        }
    }
}
// Changing Vowel
int vowel_(char *s)
{
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
        {
            c++;
        }
    }
    return c;
}
int consonant(char *s)
{
    int c = 0, n = 0;
    c = vowel_(s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            n++;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            n++;
        }
    }
    return n - c;
}
int words(char *s)
{
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == ' ') && (s[i - 1] != ' '))
        {
            c++;
        }
    }
    return c + 1;
}
int valid(char *s)
{
    int n = 0, l = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            n++;
        }
        else if (s[i] >= 65 && s[i] <= 90)
        {
            n++;
        }
        else if (s[i] >= 90 && s[i] <= 122)
        {
            n++;
        }
        else
        {
            return 0;
        }
        l++;
    }
    if (n == l)
    {
        return 1;
    }
}
char *reverse(char *s)
{
    int n;
    for (int i = 0; s[i] != '\0'; i++)
    {
        n++;
    }
    char *s1;
    s1 = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        s[n - 1 - i] = s1[i];
    }
    return s1;
}
int main()
{
    char s1[] = "Howyou";
    char *p = reverse(s1);
    for (int i = 0; p[i]!=0; i++)
    {
        printf("%c",p[i]);
    }
    
    free(p);
    return 0;
}