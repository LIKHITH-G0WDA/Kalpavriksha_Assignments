#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_dig(char c)
{
    if(c>='0' && c<='9')
        return 1;
    else
        return 0;
}

int calc_exp(int num1, int num2, char operator)
{
    switch(operator)
    {
        case '+': return num1+num2;
        case '-': return num1-num2;
        case '*': return num1*num2;
        case '/': 
        if(num2!=0)
            return num1/num2;
        else
        {
            printf("Can't divide by zero");
            exit(1);
        }
    }
}

int evaluate_exp(char exp[])
{
    int numstack[100], top=0;
    char opstack[100], e;
    int optop=0;
    int num=0, result;

    for(int i=0;exp[i]!='\0';i++)
    {
        e=exp[i];
        if (is_dig(e))
        {
            num=num*10+(e-'0');
        }
        else if(e=='+' || e=='-' || e=='*' || e=='/')
        {
            numstack[top++]=num;
            opstack[optop++]=e;
            num=0;
        }
        else
        {
            printf("Invalid symbol");
            exit(1);
        }
    }
    numstack[top++]=num;
    for(int i=0;i<optop;i++)
    {
        if(opstack[i]=='*' || opstack[i]=='/')
        {
            numstack[i]=calc_exp(numstack[i],numstack[i+1],opstack[i]);
            for(int j=i+1;j<top-1;j++)
            {
                numstack[j]=numstack[j+1];
            }
            for(int j=i;j<optop-1;j++)
            {
                opstack[j]=opstack[j+1];
            }
            top--;
            optop--;
            i--;
        }
    }
    result=numstack[0];
    for(int i=0;i<optop;i++)
    {
        result=calc_exp(numstack[i],numstack[i+1],opstack[i]);
    }
    
    return result;
}


int main()
{
    char exp[100]; 
    printf("Enter a math expression:");
    gets(exp);
    printf("Result: %d", evaluate_exp(exp));
}

