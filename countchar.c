/* a program to compress a string by replacing consecutive occurrences of the same 
character with the character followed by the count */
#include <stdio.h>
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
int main() {
    char ch[1000],ans[1000];
    printf("enter the string: ");
    scanf("%s",ch);
    int n=len(ch);
    int count=1,j=0;
    for(int i=1;i<n;i++)
    {
        if(ch[i]==ch[i-1])
        {
            count++;
        }
        else
        {
            ans[j++]=ch[i-1];
            ans[j++]=count+'0';
            count=1;
        }
    }
    ans[j++]=ch[n-1];
    ans[j++]=count+'0';
    ans[j]='\0';
    
    if(len(ans)<=n)
        printf("%s",ans);
    else
        printf("%s",ch);
}
