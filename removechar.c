// a program to remove all instances of a specific character from a string
#include <stdio.h>

int main() {
    char str[1000],ch,ans[1000];
    printf("enter the sentence: ");
    scanf("%[^\n]%*c",str);
    printf("\nenter the char to remove: ");
    scanf("%c",&ch);
    int j=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!=ch)
        {
            ans[j++]=str[i];
        }
    }
    ans[j]='\0';
    printf("%s",ans);
}
