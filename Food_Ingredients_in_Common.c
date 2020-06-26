#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max_food 100
#define max_ingre 10
#define max_len 65
void sort_food(char *samep[], int count)
{
    for(int i=0; i<count-1; i+=1)
    {
        for(int j=0; j<count-1-i; j+=1)
        {
            if(strcmp(samep[j],samep[j+1])>0)
            {
                char *temp = samep[j];
                samep[j] = samep[j+1];
                samep[j+1] = temp;
            }
        }
    }
}
int main()
{
    int food_num=0;
    scanf("%d",&food_num);

    char ingre[max_food][max_ingre][max_len];
    char food[max_food][max_len] = {};
    for(int i=0; i<food_num; i+=1)
    {
        scanf("%s", food[i]);
        int ingre_num = 0;
        scanf("%d",&ingre_num);
        for(int j=0; j<ingre_num; j+=1)
        {
            scanf("%s",ingre[i][j]);
        }
    }
    int quries =0;
    scanf("%d",&quries);
    char food1[max_len] = {}, food2[max_len] = {};
    for(int i=0; i<quries; i+=1)
    {
        scanf("%s%s",food1, food2);
        int food1_loc = 0, food2_loc = 0;
        for(int j=0; j<food_num; j+=1)
        {
            if(strcmp(food1, food[j])==0)
            {
                food1_loc = j;
            }
            if(strcmp(food2, food[j])==0)
            {
                food2_loc=j;
            }
        }
        int count=0;
        char *samep[max_ingre];
        char thesame[max_ingre][max_len] = {};
        for(int j=0; j<max_ingre; j+=1)
        {
            for(int k=0; k<max_ingre; k+=1)
            {
                if(strcmp(ingre[food1_loc][j], ingre[food2_loc][k])==0 && isalpha(ingre[food1_loc][j][0]))
                {
                    strcpy(thesame[count],ingre[food1_loc][j]);
                    samep[count] = thesame[count];
                    count+=1;
                }
            }
        }
        if(strcmp(thesame[0],"")!=0)
        {
            sort_food(samep,count);
            for(int i=0; i<count; i+=1)
            {
                printf("%s",samep[i]);
                if(i!=count-1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else
        {
            printf("nothing\n");
        }
    }
    return 0;
}
