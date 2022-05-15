#include<stdio.h>
int main()
{
    char s[] = "bhvaya";
    char s1[] = "bhvaya";
    int t =0 ;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] > s1[i])
        {
            printf("Second string is smaller");
            t=1;
            break;
        }   
        else if (s[i] < s1[i])
        {
            printf("First string is smaller");
            t=1;
            break;
        }
    }
    if(t==0){
        printf("Both r equal!!");
    }

    return 0;
}