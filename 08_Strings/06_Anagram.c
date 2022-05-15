// Set of strings formed by same set of elements!!
#include <stdio.h>
int main(){
    char s[]="verbose";
    char s1[]="observe";
    int h[26]={0};
    for (int i = 0;s[i]!=0; i++)
    {
        h[s[i]-97]++;
    }
    for (int i = 0;s1[i]!=0; i++)
    {
        h[s1[i]-97]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if(h[i]!=0){
            puts("Strings are Not Anagram");
            return 0;
        }
    }
    puts("Strings are Anagram")    ;
    
    return 0;
}