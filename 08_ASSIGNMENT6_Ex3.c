/******************************************************************************
 * File: expr.c
 *
 * Description:
 *    Tính biểu thức hậu tố (Reverse Polish Notation).
 *
 * Author: ChatGPT
 * Date: 2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTACK 100

int stack[MAXSTACK];
int top = -1;

/******************************************************************************
 * Function: push
 ******************************************************************************/
void push(int val)
{
    stack[++top] = val;
}

/******************************************************************************
 * Function: pop
 ******************************************************************************/
int pop(void)
{
    return stack[top--];
}

/******************************************************************************
 * Function: main
 ******************************************************************************/
int main(int argc, char *argv[])
{
    int i, a, b;

    for(i = 1; i < argc; i++)
    {
        if(isdigit(argv[i][0]))
        {
            push(atoi(argv[i]));
        }
        else
        {
            b = pop();
            a = pop();

            switch(argv[i][0])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}