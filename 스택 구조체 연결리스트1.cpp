#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Stack
{
    int data;
    struct stackNode *link;
}StackNode;

StackNode *top=NULL;

typedef struct{
    StackNode*head;
}linkedList_h;

void push(int x)
{
    StackNode *new;
    newx = (stackNode*)malloc(sizeof(stackNode));
    new -> data= x;
    new ->link = top;
    top = new;
}

int pop()
{
    return top->data;
    top = top->link;
    temp = temp->

}
void printStack(){
    for(int i = 0; i<=top;i++)
        printf("%d",stack->temp.data);
    printf("\t");
}

int main(void)
{
    int item;
    
    printf("\n**operation**\n");
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();

    item = pop();
    printStack();
    printf("\tpop => ");

    item = pop();
    printStack();
    printf("\tpop => ");

    item = pop();
    printStack();
    printf("\tpop => ");

    getchar();
}
