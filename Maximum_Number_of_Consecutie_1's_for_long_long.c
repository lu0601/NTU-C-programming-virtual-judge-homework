#include <stdio.h>
int main()
{
    long long int num=0;
    /*FILE *fp = fopen("ans.txt","w");
    if(fp==NULL)
    {
        printf("Cannot open ans.txt.\n");
        return 0;
    }*/
    while(scanf("%lld",&num)==1)
    {
        int one_count=0;
        while(num>0)
        {
            int temp = num%2;
            if(temp==1)
            {
                one_count+=1;
            }
            num /= 2;
        }
        printf("%d\n",one_count);
    }
}
