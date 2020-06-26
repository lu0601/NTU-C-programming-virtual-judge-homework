#include <stdio.h>
int use(int a, int b, int c, int da, int db, int dc, int ea, int eb, int ec, int fa, int fb, int fc)
{
    //printf("\n-----------------------\n");
    //printf("%d %d %d \n",a,b,c);
    if(a==0 && b==0 && c==0)
    {
        return 1;
    }
    if(a<0 || b<0 || c<0)
    {
        return 0;
    }
    return (use(a-da, b-db, c-dc, da, db, dc, ea, eb, ec, fa, fb, fc)||use(a-ea, b-eb, c-ec, da, db, dc, ea, eb, ec, fa, fb, fc) || use(a-fa, b-fb, c-fc, da, db, dc, ea, eb, ec, fa, fb, fc));
    //printf("\n-----------------------\n");
}
int main()
{
    int da=0, db=0, dc=0;
    int ea=0, eb=0, ec=0;
    int fa=0, fb=0, fc=0;
    int q_num=0;
    scanf("%d %d %d", &da, &db, &dc);
    scanf("%d %d %d", &ea, &eb, &ec);
    scanf("%d %d %d", &fa, &fb, &fc);
    scanf("%d",&q_num);
    for(int i=0; i<q_num; i+=1)
    {
        int a=0, b=0, c=0, ans=0;
        scanf("%d%d%d", &a, &b, &c);
        ans = use(a, b, c, da, db, dc, ea, eb, ec, fa, fb, fc);
        if(ans==1)
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
