#include <stdio.h>
int maze(int r, int c)
{
    if(r<0 || c<0)
    {
        return 0;
    }
    else if(r==0 && c==0)
    {
        return 1;
    }
    else
    {
        return maze(r-1, c) + maze(r, c-1);
    }
}
int main()
{
    int r=0, c=0;
    scanf("%d%d",&r,&c);
    printf("%d\n", maze(r-1, c-1));
    return 0;
}
