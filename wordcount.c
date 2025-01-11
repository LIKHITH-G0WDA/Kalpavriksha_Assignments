//program to count the number of words in a given string
#include <stdio.h>

int main() {
    char sent[1000];
    printf("enter a string : ");
    fgets(sent,sizeof(sent),stdin);
    int i=0,count=0,word=0;
    while(sent[i]!='\0')
    {
        if(sent[i]!=' ' && !word)
        {
            word=1;
            count++;
        }
        else if(sent[i]==' ')
            word=0;
        i++;
    }
    printf("%d",count);
}
