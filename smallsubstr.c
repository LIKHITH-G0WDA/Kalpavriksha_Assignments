//smallest substring in a given string that contains all the characters of another string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* smallsub(char* str,char* pat)
{
    int len1=len(str);
    int len2=len(pat);
    if(len1==0 || len2==0)
    {
        return "";
    }
    int ccount[256]={0};
    for(int i=0;i<len2;i++)
    {
        ccount[pat[i]]++;
    }
    int start=0,end=0,minlen=len1+1,mstart=0,count=0;
    while(end<len1)
    {
        ccount[str[end]]--;
        if(ccount[str[end]]>=0)
        {
            count++;
        }
        while(count==len2)
        {
            if(minlen>end-start+1)
            {
                minlen=end-start+1;
                mstart=start;
            }
            ccount[str[start]]++;
            if(ccount[str[start]]>0)
            {
                count--;
            }
            start++;
        }
        end++;
    }
    if(minlen==len1+1)
    {
        return"";
    }
    char* result=(char*)malloc(minlen+1);
    strncpy(result,str+mstart,minlen);
    result[minlen]='\0';
    return result;
}

int main(){
    char str[100],pat[100];
    printf("enter the main string: ");
    scanf("%s",str);
    printf("enter the pattern string: ");
    scanf("%s",pat);
    char* substr=smallsub(str,pat);
    if(strlen(substr)>0)
    {
        printf("%s",substr);
    }
    else
    {
        printf("no substring");
    }
    free(substr);
}
