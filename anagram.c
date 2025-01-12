//program to check if two strings are anagrams of each other
#include <stdio.h>
int len(char *str)
{
    int length=0;
    while(*str!='\0')
    {
        str++;
        length++;
    }
    return length;
}

char lower(char c)
{
    if(c>='A' && c<='Z')
        return c+32;
    else
    return c;
}
int main() {
    char str1[100],str2[100];
    printf("enter two strings: ");
    scanf("%s",str1);
    scanf("%s",str2);
    if(len(str1)!=len(str2))
    {
        printf("false");
        return 0;
    }
    int frq1[26]={0};
    int frq2[26]={0};
    for (int i=0; str1[i]!='\0'; i++) 
    {
        str1[i] = lower(str1[i]);
        str2[i] = lower(str2[i]);
        frq1[str1[i] - 'a']++;
        frq2[str2[i] - 'a']++;
    }
    
    for(int i=0;i<26;i++)
    {
        if(frq1[i]!=frq2[i])
        {
            printf("false");
            return 0;
        }
        
    }
    printf("true");
}
