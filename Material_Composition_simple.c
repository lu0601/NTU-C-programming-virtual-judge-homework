#include <stdio.h>
int main()
{
    int da=0, db=0, dc=0;
    int ea=0, eb=0, ec=0;
    int fa=0, fb=0, fc=0;
    int q_num=0;
    scanf("%d %d %d", &da, &db, &dc);
    scanf("%d %d %d", &ea, &eb, &ec);
    scanf("%d %d %d", &fa, &fb, &fc);
    int a_sum=da+ea+fa;
    int b_sum=db+eb+fb;
    int c_sum=dc+ec+fc;
    scanf("%d", &q_num);
    for(int i=0; i<q_num; i+=1)
    {
        int a=0, b=0, c=0;
        scanf("%d%d%d", &a, &b, &c);
        if(a>=a_sum && b<=b_sum && c<=c_sum)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}
