#include <stdio.h>
#include<stdlib.h>
#include <memory.h>
#include<string.h>

int main()
{
    int i =0;
    int  number;
    int index,value;
    int *pi;
    int *insert_pi;
    int *delete_pi;

    printf("how many number : ");
    scanf("%d",&number);

    pi = (int *) malloc(number * sizeof(int));
    insert_pi = (int *) malloc((number+1) * sizeof(int));
    delete_pi = (int *) malloc((number-1) * sizeof(int));

    if(pi ==NULL)
    {
        printf("error\n");
        exit(1);
    }

    if(insert_pi ==NULL)
    {
        printf("error\n");
        exit(1);
    }

    if(delete_pi ==NULL)
    {
        printf("error\n");
        exit(1);
    }

    for(i = 0; i<number; i++)
    {
        scanf("%d",&pi[i]);
    }
    for(i =0; i<number; i++)
    {
        printf("%d\t",pi[i]);
    }

    printf("input.index : ,input.value : ");
    scanf("%d%d",&index,&value);

    for(i=0;i<number;i++)
    {
        if(i<index-1)
            insert_pi[i]=pi[i];
        else if(i>=index-1)
                insert_pi[i+1] = pi[i];
    }
    insert_pi[index-1] = value;

    for(i =0; i<number+1; i++)
    {
        printf("%d\t",insert_pi[i]);
    }

    printf("delete.index : , delete.value");
    scanf("%d%d", &index,&value);
    for(i=0;i<number;i++) {
        if (i < index - 1)
            delete_pi[i] = pi[i];
        else if(i >= index - 1)
        delete_pi[i - 1] = pi[i];
    }
    delete_pi[index-1] = value;

    for(i =0; i<number+1; i++)
    {
        printf("%d\t",insert_pi[i]);
    }

    return 0;
}



