#include <stdio.h>
#include <stdlib.h>
typedef struct Year
{
    int year;
    int month;
    int day;
} Year;
int cmp(const void *x, const void *y)
{
    Year *tempx = (Year *)x;
    Year *tempy = (Year *)y;
    //printf("in cmp: %d %d %d\n", tempx->year, tempx->month, tempx->day);
    if(tempx->year<tempy->year)
    {
        return -1;
    }
    if(tempx->year>tempy->year)
    {
        return 1;
    }
    if(tempx->month<tempy->month)
    {
        return -1;
    }
    if(tempx->month>tempy->month)
    {
        return 1;
    }
    if(tempx->day<tempy->day)
    {
        return -1;
    }
    if(tempx->day>tempy->day)
    {
        return 1;
    }
    return 0;
}
Year year[1000000];
int main()
{
    int date_num=0;

    scanf("%d", &date_num);
    for(int i=0; i<date_num; i+=1)
    {
        scanf("%d%d%d", &year[i].year, &year[i].month, &year[i].day);
    }
    qsort(year, date_num, sizeof(Year), cmp);
    for(int i=0; i<date_num; i+=1)
    {
        printf("%d %d %d\n", year[i].year, year[i].month, year[i].day);
    }
}
