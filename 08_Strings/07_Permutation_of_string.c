#include <stdio.h>

// int i=0;int k=0;
void pos(char s[], int k)
{

    static int arr[10] = {0};
    static char res[10];
    int i;
    if (s[k] == '\0')
    {
        res[k]='\0';
        puts(res);
    }
    for (i = 0; s[i] != '\0'; i++)
    {
        if (arr[i] == 0)
        {
            arr[i]++;
            res[k] = s[i];
            pos(s, k + 1);
            arr[i] = 0;
        }
    }

    // // k=1,i==1
    // // arr[4]={1,0,0,0}
    // // if(i==0) -> res[k]=s[i] -> pos(i,k+1) -> arr[i]=0 ->
}

int main()
{
    char s[] = "ABC";
    pos(s, 0);
    return 0;
}