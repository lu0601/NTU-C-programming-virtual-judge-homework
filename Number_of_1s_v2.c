#include <stdio.h>
int main()
{
    int num=0;
    while(scanf("%d",&num)==1){
        int one_count=0;
        while(num>0)
        {if(num & 1 ==1){one_count+=1;}
            num = num>>1;
        }
        printf("%d\n",one_count);
    }
}
