// a program to find the longest palindromic substring in a given string
#include <stdio.h>
int palindrome(char* str, int l,int r)
{
    while(l<r)
    {
        if(str[l]!=str[r])
        {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

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
int main() {
    char str[1000];
    printf("enter the string: ");
    scanf("%[^\n]%*c",str);
    int n=len(str);
    int length,maxlen=1,startindex=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(palindrome(str,i,j))
            {
                length=j-i+1;
                if(length>maxlen)
                {
                    maxlen=length;
                    startindex=i;
                }
            }
        }
    }
    for(int i=startindex; i<startindex+maxlen; i++) 
    {
        printf("%c",str[i]);
    }
    
}
