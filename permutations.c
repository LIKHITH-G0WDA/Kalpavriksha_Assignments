//Generate and print all permutations of a given string
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
void swap(char *x,char *y)
{
    char temp=*x;
    *x=*y;
    *y=temp;
}
void repeat(char *str,int l,int r)
    {
        int first=1;
        if(l==r)
        {
            printf("\"%s\"",str);
            return;
        }
            for(int i=l;i<=r;i++)
            {
                swap((str+l),(str+i));
                if(!first)
                    printf(",");
                else
                    first=0;
                repeat(str,l+1,r);
                swap((str+l),(str+i));
                
            }
            
    }
    
int main() {
    char str[100];
    printf("enter a string: ");
    scanf("%s",str);
    int n=len(str);
    printf("[");
    repeat(str,0,n-1);
    printf("]");
}
