#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

#define ASC 0
#define DSC 1

typedef struct fruit{
    int id;
    char name[20];
    int price;
    struct fruit *link;
}Fruit;

int addHead(Fruit **head,int id,char *name,int price);
int removeHead(Fruit **head);
int removeAll(Fruit **head);
void printList(Fruit *head);
int getId(Fruit *head,char *name);
int getPosition(Fruit *head,int id);
int removeById(Fruit **head,int id);
int removeByPosition(Fruit **head,int position);
Fruit *getNodeByPosition(Fruit *head,int position);
int putNodeByPosition(Fruit **head,int position,Fruit *node);
int getCount(Fruit *head);
Fruit *newNode(int id,char *name,int price);
int sortByPrice(Fruit **head,int order);
int sortByName(Fruit **head,int order);
int swap(Fruit **head,Fruit *node1,Fruit * node2);

int main(void) {
    printf("(i) This Program is a List exam. \n");

    Fruit *head = NULL;
    int issuedId=0;

    addHead(&head,issuedId++,"apple",1500);
    addHead(&head,issuedId++,"banana",1000);
    addHead(&head,issuedId++,"pear",3000);
    addHead(&head,issuedId++,"melon",10000);
    addHead(&head,issuedId++,"mango",15000);
    printList(head);

    Fruit *node=newNode(issuedId++,"berry",8000);
    if(putNodeByPosition(&head,3,node))
        printf("(!) put position 3 is success! \n");
    else printf("(!) put position 3 is failed! \n");
    printList(head);

    sortByName(&head,ASC);
    printf("(i) Sorted by ASC\n");
    printList(head);

    sortByName(&head,DSC);
    printf("(i) Sorted by DSC\n");
    printList(head);



    removeAll(&head);

    return 0;
}
int swap(Fruit **head,Fruit *node1,Fruit * node2)
{

    int positionNode1 = getPosition(*head,node1->id);
    int positionNode2 = getPosition(*head,node2->id);

    Fruit *prevNode1 = getNodeByPosition(*head,positionNode1-1);
    Fruit *prevNode2 = getNodeByPosition(*head,positionNode2-1);

    if(prevNode1==NULL) ///head node
        *head=node2;
    else prevNode1->link = node2;

    if(prevNode2==NULL) //head node
        *head=node1;
    prevNode2->link = node1;

    Fruit *temp = node1->link;
    node1->link = node2->link;
    node2->link = temp;

    return TRUE;

}

int sortByName(Fruit **head,int order)
{
    int count=getCount(*head);
    for(int i=0; i<count; i++)
    {


        for(int j=1+i; j<count; j++)
        {
            Fruit *selected=getNodeByPosition(*head,i);
            Fruit *current=getNodeByPosition(*head,j);
            if(order==ASC && strcmp(current->name , selected->name)<0)
                swap(head,selected,current);
            if(order==DSC && strcmp(current->name , selected->name)>0)
                swap(head,selected,current);
        }
    }


    return TRUE;

}


int sortByPrice(Fruit **head,int order)
{
    int count=getCount(*head);
    for(int i=0; i<count; i++)
    {


        for(int j=1+i; j<count; j++)
        {
            Fruit *selected=getNodeByPosition(*head,i);
            Fruit *current=getNodeByPosition(*head,j);
            if(order==ASC && current->price < selected->price)
                swap(head,selected,current);
            if(order==DSC && current->price > selected->price)
                swap(head,selected,current);
        }
    }


    return TRUE;

}

int putNodeByPosition(Fruit **head,int position,Fruit *node)
{

    if(position<0 || position >getCount(*head)) return FALSE;
    if(position==0)                              //insert head position
    {
        node->link=*head;
        *head=node;
    }
    else if(position==getCount(*head))           //insert into last position
    {
        Fruit *last=getNodeByPosition(*head,getCount(*head)-1);
        if(last !=NULL) return FALSE;
        last->link=node;
    }
    else                                        //insert into middle position
    {
        Fruit * prev=getNodeByPosition(*head,position-1);
        Fruit * crnt=getNodeByPosition(*head,position);
        if(prev==NULL || crnt == NULL)return FALSE;
        node->link=crnt;
        prev->link=node;
    }
    return TRUE;
}

Fruit *newNode(int id,char *name,int price)
{
    if(id<0)            return NULL;
    if(name==NULL)      return NULL;
    if(price<0)         return NULL;


    Fruit * node = (Fruit *) malloc(sizeof(Fruit));
    node->id=id;
    strcpy(node->name,name);
    node->price=price;
    node->link=NULL;

    return node;

}

int removeByPosition(Fruit **head,int position){

    Fruit *node=getNodeByPosition(*head,position);
    if(node==NULL)return FALSE;
    return removeById(head,node->id);

}

int getCount(Fruit *head)
{
    int count =0;
    Fruit *current = head;
    while(current!=NULL)
    {
        current=current->link;
        count ++;
    }
    return count;
}

Fruit *getNodeByPosition(Fruit *head,int position)
{

    if(position<0)return NULL;
    if(position>=getCount(head))return NULL;
    Fruit *current=head;
    for(int i=0; i<position; i++)
        current=current->link;
    return current;
}

int removeById(Fruit **head,int id)
{
    int positionCrnt = getPosition(*head,id);
    int positionPrev=positionCrnt-1;
    int positionNext=positionCrnt+1;

    Fruit *crnt = getNodeByPosition(*head,positionCrnt);
    Fruit *prev=getNodeByPosition(*head,positionPrev);

    if(positionPrev<0) //Head node
    {
        if(crnt != NULL) *head = crnt->link;
    }
    else if(positionNext>=getCount(*head))  //Last node
    {
        if(prev != NULL) prev->link = NULL;
    }
    else //middle node
    {
        if(prev !=NULL && crnt != NULL) prev->link=crnt->link;
    }

    if(crnt != NULL)
    {
        free(crnt);
        return TRUE;
    }
    return FALSE;

}

int getId(Fruit *head,char *name){

    Fruit *current=head;
    while(current!=NULL)
    {
     if(strcmp(current->name,name)==0)
         return current->id;
     current=current->link;
    }
    return -1;
}


int getPosition(Fruit *head,int id){

    int postion=0;

    Fruit *current=head;
    while(current!= NULL)
    {
        if(current->id==id)
            return postion;
        current=current->link;
        postion++;
    }
    return -1;
}

int addHead(Fruit **head,int id,char *name,int price)
{
    Fruit *node=newNode(id,name,price);
    if(node==NULL) return FALSE;

    if(head != NULL)node->link=*head;

    *head=node;

    return TRUE;
}

int removeHead(Fruit **head)
{
    if(*head==NULL)return FALSE;

    Fruit *node= *head;
    *head=node->link;

    free(node);

    return TRUE;
}

int removeAll(Fruit **head)
{
    if(head==NULL) return FALSE;
    while(*head !=NULL)removeHead(head);
    return TRUE;
}

void printList(Fruit *head){

    Fruit * current= head;
    int position=0;
    while(current!=NULL)
    {
        printf("(i)  Fruit[%d] %s(%d)'s price is %d\n",position++,current->name, current->id,current->price);
        current=current->link;
    }
    return;
}
