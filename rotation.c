//a program to check if one string is a rotation of another using only one call to a string 
//concatenation function
#include <stdio.h>
int main() {
    char str1[100],str2[100],supstr[200];
    printf("enter string 1 and string 2: ");
    scanf("%s",str1);
    scanf("%s",str2);
    int i,j;
    for(i=0;str1[i]!='\0';i++)
    {
        supstr[i]=str1[i];
    }
    for(j=0;str1[j]!='\0';j++)
    {
        supstr[i+j]=str1[j];
    }
    supstr[i+j]='\0';
    int found=0;
    for(int i=0;supstr[i]!='\0';i++)
    {
        int j=0;
        while(supstr[i+j]==str2[j])
        {
            j++;
        }
        if(str2[j]=='\0')
        {
            printf("true");
            found=1;
            break;
        }
      
    }
    if(!found)
    printf("false");
    
}
