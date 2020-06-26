#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Expense
{
    int year, month,date,amount;
    char cateory[40];
}Expense;
Expense expense[32767];
int cmp(const void *x, const void *y)
{
    Expense *tempx = (Expense *)x;
    Expense *tempy = (Expense *)y;
    if(tempx->year > tempy->year)
    {
        return 1;
    }
    else if(tempx->year < tempy->year)
    {
        return -1;
    }
    if(tempx->month > tempy->month)
    {
        return 1;
    }
    else if(tempx->month < tempy->month)
    {
        return -1;
    }
    if(tempx->date > tempy->date)
    {
        return 1;
    }
    else if(tempx->date < tempy->date)
    {
        return -1;
    }
    return strcmp(tempx->cateory, tempy->cateory);
}
int main()
{
    int expense_num=0;
    while(scanf("%d%d%d%s%d", &expense[expense_num].year, &expense[expense_num].month, &expense[expense_num].date, expense[expense_num].cateory, &expense[expense_num].amount)==5)
    {
        expense_num+=1;
    }
    qsort(expense, expense_num, sizeof(Expense), cmp);
    for(int i=0;i<expense_num;)
    {
        int sum=0;
        int same = i;
        while (i < expense_num && (expense[same].year == expense[i].year) &&(expense[same].month == expense[i].month) && (expense[same].date == expense[i].date ) && !strcmp(expense[same].cateory,expense[i].cateory))
        {
            sum += expense[i].amount;
            i+=1;
        }
        printf("%d %d %d %s %d\n", expense[same].year, expense[same].month, expense[same].date, expense[same].cateory, sum);
    }
    return 0;
}
