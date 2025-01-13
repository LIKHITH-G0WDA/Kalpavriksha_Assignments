// program in C to validate whether a given string is a valid IPv4 address
#include <stdio.h>
#include <string.h>

int len(char *c)
{
    int length=0;
    while(*c!='\0')
    {
        c++;
        length++;
    }
    return length;
}

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

int main()
{
    char ip[16];
    printf("enter IPV4 address: ");
    scanf("%s",ip);
    int count=0;
    char block[4]={0};
    int blockind=0;
    int n=len(ip);

    for(int i=0;i<=n;i++)
    {
        if(ip[i] == '.'||ip[i]=='\0')    
        {
            block[blockind]='\0';  
            if (len(block)==0 || (block[0]=='0' && len(block)>1) || atoi(block)<0 || atoi(block)>255)
            {
                printf("Invalid");
                return 0;
            }
            count++;
            blockind=0;  
            if(count>4)
            {
                printf("Invalid");
                return 0;
            }
        }
        else if(isnum(ip[i]))
        {
            block[blockind++]=ip[i];  
        }
        else
        {
            printf("Invalid");
            return 0;
        }
    }

    if (count!=4)  
    {
        printf("Invalid");
    }
    else
    {
        printf("Valid");
    }

}
