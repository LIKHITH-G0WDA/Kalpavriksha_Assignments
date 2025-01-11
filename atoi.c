// a program to implement the atoi() function
#include <stdio.h>

int isnum(char ch)
{
    return ch>='0' && ch<='9';
}

int atoi(char *str)
{
    while(*str==' ')
        str++;
    if(*str=='\0')
        return 0;
    int sign=1;
    if(*str=='-')
    {
        sign=-1;
        str++;
    }
    else if(*str=='+')
    {
        str++;
    }
    
    int ans=0;
    while(*str!='\0' && isnum(*str))
    {
        ans=ans*10+(*str-'0');
        str++;
    }
    if(*str=='\0')
        return sign*ans;
    else
        return 0;
        
}
int main() {
    char ch[100];
    printf("enter the string: ");
    scanf("%[^\n]%*c",ch);
    printf("%d\n",atoi(ch));
}
