/*program to remove adjacent duplicate characters in a string recursively until no adjacent duplicates remain*/
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
int main() {
    char str[100];
    printf("enter the string: ");
    scanf("%s",str);
    int n=len(str);
    int t=-1;
    char stk[100];
    for(int i=0;i<n;i++)
    {
        if(t>=0 && stk[t]==str[i])
            t--;
        else
            stk[++t]=str[i];
    }
    stk[t+1]='\0';
    if(t==-1)
    printf("\"\"");
    else
    printf("%s",stk);
}
