#include <stdio.h>
#include <stdlib.h>
typedef struct Point
{
    int x;
    int y;
}Point;
int cmp(const void *x, const void *y)
{
    Point *tempx = (Point *)x;
    Point *tempy = (Point *)y;
    long long suma = (long long)tempx->x*tempx->x + (long long )tempx->y*tempx->y;
    long long sumb = (long long)tempy->x*tempy->x + (long long )tempy->y*tempy->y;
    if(suma<sumb)
    {
        return -1;
    }
    if(suma>sumb)
    {
        return 1;
    }
    if(tempx->x < tempy->x)
    {
        return -1;
    }
    if(tempx->x > tempy->x)
    {
        return 1;
    }
    if(tempx->y <tempy->y)
    {
        return -1;
    }
    if(tempx->y > tempy->y)
    {
        return 1;
    }
    return 0;
}
int main()
{
    Point point[120000];
    int point_count=1;
    long long ans = 0;
    while(scanf("%d%d", &point[point_count].x, &point[point_count].y)==2)
    {
        point_count+=1;
    }
    qsort(point+1, point_count, sizeof(Point), cmp);

    for(int i=1;i<=point_count;i+=1)
    {
        long long x = point[i].x - point[i-1].x;
        long long y = point[i].y - point[i-1].y;
        ans += x*x+y*y;
    }
    printf("%lld\n", ans);
    return 0;
}
