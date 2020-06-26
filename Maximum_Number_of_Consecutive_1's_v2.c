#include <stdio.h>
#define max_size 33
int main()
{
    int num=0;

    /*FILE *fp = fopen("ans.txt","w");
    if(fp==NULL)
    {
        printf("Cannot open ans.txt.\n");
        return 0;
    }*/
    while(scanf("%d",&num)!=EOF)
    {
        int count=0;
        int temp = num;
        while(temp>0)
        {
            printf("temp:%d\n",temp);
            if((temp&1)==1)
            {
                count+=1;
            }
            temp>>1;
        }
        printf("%d\n",count);
    }
}
