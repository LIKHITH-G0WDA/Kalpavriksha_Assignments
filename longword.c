// program to find the longest word in a given sentence
#include <stdio.h>
void copy(char* longword,char* word)
{
    int i=0;
    while(word[i]!='\0')
    {
        longword[i]=word[i];
        i++;
    }
    longword[i]='\0';
}
int main() {
    char sent[1000];
    printf("enter a sentence: ");
    scanf("%[^\n]%*c",sent);
    char word[100],longword[100];
    int length,maxlen,i=0,j=0;
    while(sent[i]!='\0')
       {
            if(sent[i]==' ' || sent[i]=='\0')
            {
                word[j]='\0';
                if(length>maxlen)
                {
                    length=maxlen;
                    copy(longword,word);
                }
            
                j=0;
                length=0;
            }
            else
            {
                word[j++]=sent[i];
                length++;
            }
            i++;
       }
       if (length>maxlen) {
        copy(longword,word);
    }
    printf("%s",longword);
}
