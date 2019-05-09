#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*typedef struct queNode
{
    int data;
    struct queNode *link;
}queNode;

queNode *top=NULL;

typedef struct{
    queNode*head;
}linkedList_h;*/
int que[50];
int front = -1;
int rear = -1;
int isfull(){
    if(rear ==50)
        return 1;
    else return 0;
}


void enQueue(int x)
{
    if(isfull())
        return ;
  rear++;
  que[rear] = x;
}

int deQueue()
{
    front++;
    return  que[front];

}
void printQue(){
    for(int i = front+1; i<=rear;i++)
        printf("%d",que[i]);
    printf("\t");
}

int main(void)
{
    printf("\n*****que op*****\n");
    int item;

    enQueue(1); printQue(); 
    enQueue(2); printQue(); 
    enQueue(3); printQue();

    item = deQueue();
    printf("\tdeQue => ");
    printQue();


    item = deQueue();
    printf("\tdeQue => ");
    printQue();


    item = deQueue();
    printf("\tdeQue => ");
    printQue();


}

