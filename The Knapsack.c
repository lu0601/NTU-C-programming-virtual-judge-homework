#include <stdio.h>
typedef struct Object
{
    int w;
    int v;
}Object;
void sum(int n, int m, int w, int v, Object object[], int loc, int *ans)
{
    if (w > m)
    {
        return ;
    }
    if(v > *ans)
    {
        *ans = v;
    }
    if (loc == n)
    {
        return ;
    }
    sum(n, m, w+object[loc].w, v+object[loc].v,object, loc+1, ans);
    sum(n, m, w, v, object, loc+1, ans);
}
int main()
{
    int n, m;
    Object object[20];
    for (int i = 0; i < 20; i+=1)
    {
        object[i].w=0;
        object[i].v=0;
    }
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &object[i].w, &object[i].v);
        }
        int ans = 0;
        sum(n, m, 0, 0, object, 0, &ans);
        printf("%d\n", ans);
    }
    return 0;
}
