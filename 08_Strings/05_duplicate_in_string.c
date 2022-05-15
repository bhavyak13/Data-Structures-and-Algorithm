
// Method 1 Comparing with other strings !!
// #include <stdio.h>
// int main()
// {
//     char s[] = "uttttiiiiiiii";
//     int count = 0;
//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         for (int j = i + 1; s[j] != '\0'; j++)
//         {
//             if (s[i] == s[j] && s[j]!='0')
//             {
//                 s[j] = '0';
//                 count++;
//             }
//         }
//     }
//     printf("%d", count);

//     return 0;
// }

// Method 2!
// Using hash table!
// #include <stdio.h>
// int main()
// {
//     // char s[]="bhavya";
//     char s[] = "uttttiiiiiiii";
//     int H[26] = {0};
//     // this h is array containing 26 elements indexed froem 0 to 25
//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         int x = s[i] - 97;
//         H[x]++;
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (H[i] > 1)
//         {
//             printf("Duplicate Letter: %c\n",i+97);
//             printf("NO. of times : %d\n",H[i]);
//         }
//     }
//     return 0;
// }

// Method 3  Using Bits!!
#include <stdio.h>
int main()
{
    int h = 0;
    int x = 0;
    char s[] = "finding";
    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << (s[i] - 97);
        if (x&h>0)
        {
            printf("Duplicate Letter : %c\n", s[i]);
        }
        else{
            h=x|h;
        }
    }

    return 0;
}