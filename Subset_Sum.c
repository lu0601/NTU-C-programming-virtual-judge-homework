#include <stdio.h>
void subset_sum( int ans[], int arr[], int sum, int data_num,int idx)
{
    if (idx == data_num)
    {
        ans[sum]+=1;
        return ;
    }
    subset_sum(ans,arr, sum, data_num, idx+1);
    subset_sum(ans,arr, sum+arr[idx], data_num, idx+1);
}
int main()
{
    int data_num =0 ;
    scanf("%d", &data_num);
    int arr[15] = {}, ans[1024] = {};
    for (int i = 0; i < data_num; i+=1)
    {
        scanf("%d", &arr[i]);
    }
    subset_sum( ans, arr, 0,data_num, 0);
    int question = 0;
    while (scanf("%d", &question) == 1)
    {
        printf("ans:");
        printf("%d\n", ans[question]);
    }
    return 0;
}
