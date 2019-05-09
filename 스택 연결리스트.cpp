#include <stdio.h>

int stack[100];
int top = -1;

void push(int item)
{
    if(top>=100)
        printf("overflow");
    else
        top++;
        stack[top] = item;

}

void pop()
{
    if(top <0)
        printf("underflow");
    else
        top--;
}

void printStack()
{
    for(int i = 0; i<=top;i++)
        printf("%d",stack[i]);
    printf("\t");
}

int main(void)
{
    printf("\n** stack**\n");
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();


    printf("\tpop=>");
    pop();
    printStack();

    printf("\tpop=>");
    pop();
    printStack();

    printf("\tpop=>");
    pop();
    printStack();
    getchar();
}
