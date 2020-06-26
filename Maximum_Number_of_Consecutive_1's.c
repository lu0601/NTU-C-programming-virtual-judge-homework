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
        int data[max_size]= {};
        int one_count=0;
        while(num>0)
        {
            int temp = num%2;
            if(temp==1)
            {
                data[one_count] = 1;

            }
            one_count+=1;
            num /= 2;
        }
        int max_count=0, temp=0;
        for(int i=0; i<max_size; i+=1)
        {
            if(data[i]==1)
            {
                temp+=1;
                //printf("data[%d] => temp:%d",i,temp);
                if(temp>max_count)
                {
                    max_count = temp;
                }
            }
            else if(data[i]==0)
            {
                temp=0;
                //printf("temp:%d\n",temp);
            }
            //printf("%d ",data[i]);
        }
        printf("%d\n",max_count);
    }
}
