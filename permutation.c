#include <stdio.h>
#define max_data_num 16
void sort(int arr[], int n)
{
    for(int i=n-2; i>=0; i-=1)
    {
        for(int j=0; j<=i; j+=1)
        {
            if(arr[j] > arr[j+1])
            {
                //printf("%d vs %d\n", arr[j],arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int swap(int *data1, int *data2)
{
    int temp=0;
    temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}
int permutation(int arr[], int n)
{
    for(int i=n-2; i>=0; i-=1)
    {
        if(arr[i] < arr[i+1])
        {
            int j = i+1;
            while(j<n && arr[j]>arr[i])
            {
                j+=1;
            }
            j-=1;
            swap(&arr[i], &arr[j]);
            for(int p = i+1, q = n-1; p<q ; p+=1, q-=1)
            {
                swap(&arr[p], &arr[q]);
            }
            return 1;
        }
    }
    return 0;
}
int main()
{
    int data_num=0;
    int data[max_data_num] = {};
    scanf("%d", &data_num);
    for(int i=0; i<data_num; i+=1)
    {
        scanf("%d", &data[i]);
    }
    //printf("---------------------\n");
    sort(data, data_num);
    for(int i=0; i<data_num; i+=1)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    //system("pause");
    while(permutation(data, data_num))
    {
        for(int i=0; i<data_num; i+=1)
        {
            printf("%d", data[i]);
            if(i==data_num-1)
            {
                printf(" \n");
            }
            else
            {
                printf(" ");
            }
        }
    }
    return 0;
}
