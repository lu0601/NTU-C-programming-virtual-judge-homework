#include <stdio.h>
#include <string.h>
int find_loc(char result[], char cat[])
{
    int re_len = strlen(result);
    int cat_len = strlen(cat);
    int cat_loc = -1;
    int check=0;
    for(int i=0;i<re_len;i+=1)
    {
        if(strncmp(result+i, cat, strlen(result+i))==0 && check==0)
        {
            //printf("%d\n",cat_loc);
            cat_loc = i;
            check = 1;
        }
    }
    return cat_loc;
}

int main()
{
    printf("%s\n",str1);
    char result[128] = {};
    char cat[128] = {};
    while(scanf("%s",&cat)==1)
    {
        printf("##%d\n",find_loc(result, cat));
        if(find_loc(result, cat)==-1)
        {
            strcat(result, cat);
            printf("%s\n",result);
        }
        else if(find_loc(result,cat)>=0)
        {
            //printf("*%d\n",find_loc(result, cat));
            printf("result:%s\ncat:%s\n",result,cat);
            strcpy(result+find_loc(result,cat), cat);
            printf("final:%s\n",result);
        }
        char str1[128] = "ppqppqqqqppppqqqpppppqqqqqppppqqqppppqqpppqqqqqqppppqpqqpqqpqpqqpppqqpppqpppqqpqpqqqqqppqpqpppppqpabcdefg";
        printf("***********%d\n",strcmp(result, str1));
    }
    return 0;
}
