#include <stdio.h>

int main() {
    int row,col;
    printf("enter no. of rows: ");
    scanf("%d",&row);
    printf("enter no. of columns: ");
    scanf("%d",&col);
    printf("enter the names\n");
    char name[row][col][50];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("name at(%d,%d):",i,j);
            scanf("%s",name[i][j]);
        }
    }
    printf("the 2d array of names is\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%s ",name[i][j]);
        }
        printf("\n");
    }
    
    char lower(char ch)
    {
        if(ch>='A' && ch<='Z')
            return ch+32;
        else
            return ch;
    }
    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            char c=lower(name[i][j][0]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            {
                count++;
            }
        }
    }
    printf("no. of names starting with vowel: %d\n",count);
    
    char long_name[50];
    int max_len=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int len=0;
            while(name[i][j][len]!='\0')
                len++;
            if(len>max_len)
            {
                max_len=len;
                for(int k=0;k<len;k++)
                {
                    long_name[k]=name[i][j][k];
                }
            }
        }
    }
    printf("longest name is %s",long_name);
    
}
