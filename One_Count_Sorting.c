#include <stdio.h>
#include <stdlib.h>
int cmp(const void *x, const void *y)
{
    //printf("in cmp.\n");

    long long tempx = *(long long *)x;
    long long tempy = *(long long *)y;
    //printf("***x:%lld y:%lld\n", tempx, tempy);
    int xone=0;
    while(tempx!=0)
    {
        if(tempx%2==1)
        {
            xone+=1;
        }
        tempx/=2;
    }

    int yone=0;
    while(tempy!=0)
    {
        if(tempy%2==1)
        {
            yone+=1;
        }
        tempy/=2;
    }
    if(xone<yone)
    {
        return -1;
    }
    else if(xone>yone)
    {
        return 1;
    }
    else
    {
        long long a = *(long long*)x;
        long long b = *(long long*)y;
        //printf("a:%lld b:%lld\n",a,b);
        if(a<b)
        {
            return -1;
        }
        if(a>b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    long long int input;
    long long int data[10000] = {};
    int size=0;
    while(scanf("%lld", &input)==1)
    {
        //printf("%lld\n", input);
        data[size] = input;
        size+=1;
    }
    qsort(data, size, sizeof(long long), cmp);
    //printf("\n------------------\n");
    for(int i=0;i<size;i+=1)
    {
        printf("%lld\n", data[i]);
    }
    return 0;
}
