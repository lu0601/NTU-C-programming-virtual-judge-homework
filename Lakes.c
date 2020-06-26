#include <stdio.h>
#define maxn 401
#define maxm 401
int picture[maxn][maxm] = {};
int lake[maxn*maxm] = {};
int find_lake(int x, int y, int n, int m, int picture[maxn][maxm])
{
    if(m<=200 || n<=200)
    {
        if(x<0 || y<0 || x>=n || y>=m || picture[x][y]!=1)
        {
            return 0;
        }
        picture[x][y]=-1;
        return 1+find_lake(x-1, y,n,m,picture)+find_lake(x, y-1,n,m,picture)+find_lake(x+1, y,n,m,picture)+find_lake(x, y+1,n,m,picture);
    }
    else
    {
        if(x<0 || y<0 || x>=n || y>=m || picture[x][y]!=1)
        {
            return 0;
        }
        picture[x][y]=-1;
        return 1+find_lake(x-1, y,n,m,picture)+find_lake(x+1, y,n,m,picture)+find_lake(x, y-1,n,m,picture)+find_lake(x, y+1,n,m,picture);
    }
}
int main()
{
    int n=0,m=0;
    scanf("%d%d", &n, &m);
    for(int i=0; i<401; i+=1)
    {
        for(int j=0; j<401; j+=1)
        {
            picture[i][j]=0;
        }
    }
    for(int i=0; i<maxn*maxm; i+=1)
    {
        lake[i]=0;
    }
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<m; j+=1)
        {
            scanf("%d", &picture[i][j]);
        }
    }
    /*for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<m; j+=1)
        {
            printf("%d ", picture[i][j]);
        }
    }*/
    int r=0;
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<m; j+=1)
        {
            if(picture[i][j]>0)
            {
                r+=1;
                lake[r] = find_lake(i,j,n,m,picture);
            }
        }
    }
    for(int i=r-1; i>=0; i-=1)
    {
        for(int j=0; j<r; j+=1)
        {
            if(lake[j]<lake[j+1])
            {
                int temp = lake[j];
                lake[j]=lake[j+1];
                lake[j+1] = temp;
            }
        }
    }
    for(int i=0; i<r; i+=1)
    {
        printf("%d\n", lake[i]);
    }
    return 0;
}
