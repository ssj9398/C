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
        printf("\t|\t\t\t\t\t\t|\n\t|입력[0] 삭제[1] 수정[2] 출력[3] 종료[-1]\t|\n");
        printf("\t|원하는 동작을 입력해 주세요 : ");
        
        scanf("%d", &select);
        if(select == 0)
        {
            for(index = 0; index < 10; index++)if(bk[index].page == 0)break;
            if(index == 10)
            {
                printf("더 이상 저장할 공간이 없습니다.\n\n");
                continue;
            }
            printf("\t저자를 입력해 주세요 : ");
            scanf("%s", bk[index].name);
            printf("\t제목을 입력해 주세요 : ");
            scanf("%s", bk[index].title);
            printf("\tpage를 입력해 주세요 : ");
            scanf("%d", &bk[index].page);
            if(bk[index].page < 1)
            {
                printf("\t잘못된 값을 입력하셨습니다.\n\n");
                for(i = 0; i < 10; i++)bk[index].name[i] = 0;
                for(i = 0; i < 100; i++)bk[index].title[i] = 0;
                bk[index].page = 0;
                continue;
            }
            printf("\t저장되었습니다.\n\n");
        }
        else if(select == 1)
        {
            printf("\t삭제할 번호를 입력해 주세요 : ");
            scanf("%d", &del_index);
 
            if((del_index >= 0) && (del_index <= 9))
            {
                if(bk[del_index].page == 0)
                {
                    printf("\t해당되는 책이 없습니다. \n\n");
                    continue;
                }
                for(i = 0; i < 10; i++)bk[del_index].name[i] = 0;
                bk[del_index].page = 0;
                for(i = 0; i < 100; i++)bk[del_index].title[i] = 0;
                printf("\t삭제 했습니다.\n\n");
            }
            else printf("\t잘못된 번호를 입력하셨습니다.\n\n");
        }
        else if(select == 2)
        {
            printf("\t수정할 번호를 입력해 주세요 : ");
            scanf("%d", &del_index);
 
            if((del_index >= 0) && (del_index <= 9))
            {
                if(bk[del_index].page == 0)
                {
                    printf("\t해당되는 책이 없습니다. \n\n");
                    continue;
                }
                printf("\t저자를 입력해 주세요 : ");
                scanf("%s", bk[del_index].name);
                printf("\t제목을 입력해 주세요 : ");
                scanf("%s", bk[del_index].title);
                printf("\tpage를 입력해 주세요 : ");
                scanf("%d", &bk[del_index].page);
                if(bk[del_index].page < 1)
                {
                    printf("\t잘못된 값을 입력하셨습니다.\n\n");
                    for(i = 0; i < 10; i++)bk[del_index].name[i] = 0;
                    for(i = 0; i < 100; i++)bk[del_index].title[i] = 0;
                    bk[del_index].page = 0;
                    continue;
                }
                printf("\t수정 했습니다.\n\n");
            }
            else printf("\t잘못된 번호를 입력하셨습니다.\n\n");
        }
        else if(select == 3)
        {
            printf("\n");
            for(i = 0; i < 10; i++)
            {
                if(bk[i].page != 0)
                {
                    printf("\t%d번\n", i);
                    printf("\t저자 : %s\n", bk[i].name);
                    printf("\t제목 : %s\n", bk[i].title);
                    printf("\tpage : %d\n\n", bk[i].page);
                }
            }
        }
        else if(select == -1) break;
        else printf("\n\t잘못된 값을 입력했습니다.\n\n");
    }
    return 0; 
}

