#include <stdio.h>

int use(int id, int a, int b, int c, int amount, long long int D, long long int A, long long int B, long long int C)
{
    if (id == 3 || amount > D)
    {
        if(amount== D)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (id == 0)
    {
        for (int i = 0; i <= a && amount+i*A <= D; i++)
        {
            if(use(id+1, a-i, b, c, amount+i*A, D, A, B, C))
            {
                return 1;
            }
        }
    }
    if (id == 1)
    {
        for (int i = 0; i <= b && amount+i*B <= D; i++)
        {
            if(use(id+1, a, b-i, c, amount+i*B, D, A, B, C))
            {
                return 1;
            }
        }
    }
    if (id == 2)
    {
        for (int i = 0; i <= c && amount+i*C <= D; i++)
        {
            if(use(id+1, a, b, c-i, amount+i*C, D, A, B, C))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{

    int case_num=0;
    scanf("%d", &case_num);
    for(int i=0;i<case_num;i+=1)
    {
        long long A, B, C;
        int a, b, c, D;
        scanf("%d", &D);
        scanf("%d%d%d", &a, &b, &c);
        scanf("%lld%lld%lld", &A, &B, &C);
        //printf("%d %d %d \n", A, B, C);
        if(use(0, a, b, c, 0, D, A, B, C))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
