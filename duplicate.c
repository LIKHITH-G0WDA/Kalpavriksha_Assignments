//program to remove all duplicate characters from a given string
#include <stdio.h>

int main() {
    char lower(char ch)
    {
        if(ch>='A' && ch<='Z')
            return ch+32;
        return ch;
    }
    char str[100];
    int seen[26]={0};
    printf("enter a string: ");
    scanf("%s", str);
    int j=0;
    for(int i=0;str[i]!='\0';i++)
    {
        char ch=lower(str[i]);
        if(!seen[ch-'a'])
        {
            str[j++]=str[i];
            seen[ch-'a']=1;
        }
        
    }
    str[j]='\0';
    printf("%s", str);

}
