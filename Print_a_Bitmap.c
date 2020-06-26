#include <stdio.h>
#include <stdint.h>
#define max_len 32770
int main()
{
    int width =0, height=0;
    char one, zero;
    scanf("%d%d",&width, &height);
    getchar();
    scanf("%c",&one);
    getchar();
    scanf("%c",&zero);
    //printf("%d %d %c %c \n",width, height, one, zero);
    int area = width * height;
    uint32_t num=0;
    int data[32770]= {};
    for(int i=0; i<32770; i+=1)
    {
        data[i]=-1;
    }
    int loc_count = 0;
    int prev_loc = 0;
    while(scanf("%u",&num)==1)
    {
        //printf("%u\n",num);
        uint32_t temp = num;
        int loc=0;
        //printf("temp:%u\n",temp);
        loc_count+=32;
        int temp_loc = loc_count-1;
        while(temp_loc>=prev_loc)
        {
            data[temp_loc] = num%2;
            //printf("%d:%d\n",temp_loc,data[temp_loc]);
            num/=2;
            temp_loc-=1;
        }
        //printf("\n----------------------\n");
        //printf("%d\n",loc_count);
        prev_loc = loc_count;
    }
    //printf("\n");
    /*for(int i=0; i<loc_count; i+=1)
    {
        printf("%d:%d ",i,data[i]);
    }*/
    //printf("\n");
    for(int i=0;i<area;i+=1)
    {
        if(data[i]==1)
        {
            printf("%c",one);
        }
        else if(data[i]==0)
        {
            printf("%c",zero);
        }
        if(((i+1)%width)==0)
        {
            printf("\n");
        }
    }
    //printf("\n");
    return 0;
}
