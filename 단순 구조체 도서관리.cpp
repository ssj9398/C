#include <stdio.h>
#include <string.h>

struct book
{
    char name[10];
    char title[100];
    int page;
}typedef book;
 
int main()
{
    book bk[10] = {0};
    int index = 0;
    int select;
    int del_index;
    int i;
    
    while(1)
    {
    	printf("\t-------------------------------------------------\n");
        printf("\t|\t\t\t\t\t\t|\n\t|�Է�[0] ����[1] ����[2] ���[3] ����[-1]\t|\n");
        printf("\t|���ϴ� ������ �Է��� �ּ��� : ");
        
        scanf("%d", &select);
        if(select == 0)
        {
            for(index = 0; index < 10; index++)if(bk[index].page == 0)break;
            if(index == 10)
            {
                printf("�� �̻� ������ ������ �����ϴ�.\n\n");
                continue;
            }
            printf("\t���ڸ� �Է��� �ּ��� : ");
            scanf("%s", bk[index].name);
            printf("\t������ �Է��� �ּ��� : ");
            scanf("%s", bk[index].title);
            printf("\tpage�� �Է��� �ּ��� : ");
            scanf("%d", &bk[index].page);
            if(bk[index].page < 1)
            {
                printf("\t�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
                for(i = 0; i < 10; i++)bk[index].name[i] = 0;
                for(i = 0; i < 100; i++)bk[index].title[i] = 0;
                bk[index].page = 0;
                continue;
            }
            printf("\t����Ǿ����ϴ�.\n\n");
        }
        else if(select == 1)
        {
            printf("\t������ ��ȣ�� �Է��� �ּ��� : ");
            scanf("%d", &del_index);
 
            if((del_index >= 0) && (del_index <= 9))
            {
                if(bk[del_index].page == 0)
                {
                    printf("\t�ش�Ǵ� å�� �����ϴ�. \n\n");
                    continue;
                }
                for(i = 0; i < 10; i++)bk[del_index].name[i] = 0;
                bk[del_index].page = 0;
                for(i = 0; i < 100; i++)bk[del_index].title[i] = 0;
                printf("\t���� �߽��ϴ�.\n\n");
            }
            else printf("\t�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n\n");
        }
        else if(select == 2)
        {
            printf("\t������ ��ȣ�� �Է��� �ּ��� : ");
            scanf("%d", &del_index);
 
            if((del_index >= 0) && (del_index <= 9))
            {
                if(bk[del_index].page == 0)
                {
                    printf("\t�ش�Ǵ� å�� �����ϴ�. \n\n");
                    continue;
                }
                printf("\t���ڸ� �Է��� �ּ��� : ");
                scanf("%s", bk[del_index].name);
                printf("\t������ �Է��� �ּ��� : ");
                scanf("%s", bk[del_index].title);
                printf("\tpage�� �Է��� �ּ��� : ");
                scanf("%d", &bk[del_index].page);
                if(bk[del_index].page < 1)
                {
                    printf("\t�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
                    for(i = 0; i < 10; i++)bk[del_index].name[i] = 0;
                    for(i = 0; i < 100; i++)bk[del_index].title[i] = 0;
                    bk[del_index].page = 0;
                    continue;
                }
                printf("\t���� �߽��ϴ�.\n\n");
            }
            else printf("\t�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n\n");
        }
        else if(select == 3)
        {
            printf("\n");
            for(i = 0; i < 10; i++)
            {
                if(bk[i].page != 0)
                {
                    printf("\t%d��\n", i);
                    printf("\t���� : %s\n", bk[i].name);
                    printf("\t���� : %s\n", bk[i].title);
                    printf("\tpage : %d\n\n", bk[i].page);
                }
            }
        }
        else if(select == -1) break;
        else printf("\n\t�߸��� ���� �Է��߽��ϴ�.\n\n");
    }
    return 0; 
}

