#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int eval_exp(const char* exp, int* flag);
int precedence(char operator);
int calc_exp(int a, int b, char operator);

int main() 
{
    char exp[MAX];

    printf("Enter a math expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0';

    int flag = 0;
    int result = eval_exp(exp, &flag);

    if (flag == 1) 
    {
        printf("Error: Division by zero.\n");
    } 
    else if (flag == 2) 
    {
        printf("Error: Invalid expresiion.\n");
    } 
    else 
    {
        printf("Result: %d\n", result);
    }

    return 0;
}

int eval_exp(const char* exp, int* flag) 
{
    int values[MAX];      
    char operators[MAX];   
    int top = -1;    
    int op_top = -1;  

    for (int i = 0; exp[i] != '\0'; i++) 
    {
        if (isspace(exp[i])) {
            continue;
        }
        if (isdigit(exp[i])) 
        {
            int value = 0;
            while (i < strlen(exp) && isdigit(exp[i])) 
            {
                value = value * 10 + (exp[i] - '0');
                i++;
            }
            i--; 
            values[++top] = value;
        } 
        else if (exp[i] == '+' || exp[i] == '-' || 
                 exp[i] == '*' || exp[i] == '/') 
                 {
            while (op_top >= 0 && precedence(operators[op_top]) >= precedence(exp[i])) 
            {
                int b = values[top--];
                int a = values[top--];
                char op = operators[op_top--];

                if (op == '/' && b == 0) 
                {
                    *flag = 1; 
                    return 0;
                }
                values[++top] = calc_exp(a, b, op);
            }
            operators[++op_top] = exp[i];
        } 
      
        else 
        {
            *flag = 2;
            return 0;
        }
    }

    while (op_top >= 0) 
    {
        int b = values[top--];
        int a = values[top--];
        char op = operators[op_top--];

        if (op == '/' && b == 0) 
        {
            *flag = 1;
            return 0;
        }
        values[++top] = calc_exp(a, b, op);
    }

    return values[top];
}

int precedence(char operator) 
{
    if (operator == '*' || operator == '/')
    {
        return 2;
    }
    if (operator == '+' || operator == '-') 
    {
        return 1;
    }
    return 0;
}

int calc_exp(int a, int b, char operator) 
{
    switch (operator)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; 
    }
}
