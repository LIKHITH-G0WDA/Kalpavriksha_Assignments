//program to check if a given substring exists within a string
#include <stdio.h>

int main() {
    char str[1000],substr[100];
    printf("enter string and substring: ");
    scanf("%[^\n]%*c",str);
    scanf("%[^\n]%*c",substr);
    int found=0;
    for(int i=0;str[i]!='\0';i++)
    {
        int j=0;
        while(str[i+j]==substr[j])
        {
            j++;
        }
        if(substr[j]=='\0')
        {
            printf("%d",i);
            found=1;
            break;
        }
      
    }
    if(!found)
    printf("-1");
    
}
