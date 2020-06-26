#include <stdio.h>
#define max_r 13
#define max_c 13
int maze(int r, int c,int arr[][max_c])
{
    //printf("%d %d\n",r,c);
    if(r<0 || c<0 || arr[r][c]==0)
    {
        return 0;
    }
    else if(r==0 && c==0)
    {
        return 1;
    }
    else
    {
        return maze(r-1, c,arr) + maze(r, c-1,arr);
    }
}
int main()
{
    int r=0, c=0;
    scanf("%d%d",&r,&c);
    int arr[max_r][max_c] = {};
    for(int i=r-1; i>=0; i-=1)
    {
        for(int j=0; j<c; j+=1)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    /*printf("\n");
    for(int i=r-1; i>=0; i-=1)
    {
        for(int j=0; j<c; j+=1)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n", maze(r-1, c-1,arr));
    return 0;
}
