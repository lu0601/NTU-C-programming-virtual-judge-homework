#include <stdio.h>
#include <stdbool.h>
#define shelf_size 8
void take(int shelf[], int x)
{
    bool full = true;
    for(int i=0; i<shelf_size; i+=1)
    {
        if(shelf[i]==0)
        {
            full = false;
            break;
        }
    }
    bool on_shelf = false;
    int loc = 0;
    for(int i=0; i<shelf_size; i+=1)
    {
        if(shelf[i]==x)
        {
            loc = i;
            //printf("on!!\n");
            on_shelf = true;
            break;
        }
    }
    if(full)
    {
        if(on_shelf)
        {
            //printf("full; on shelf %d\n",loc);
            //int temp = shelf[loc];
            for(int i=loc; i<shelf_size-1; i+=1)
            {
                //printf("%d\n",i);
                shelf[i] = shelf[i+1];
            }
            //shelf[shelf_size-2] = shelf[shelf_size-1];
            shelf[shelf_size-1] = x;
        }
        else
        {
            //printf("full, not on shelf\n");
            for(int i=0; i<shelf_size-1; i+=1)
            {
                shelf[i] = shelf[i+1];
            }
            shelf[shelf_size-1] = x;
        }
    }
    else
    {
        if(on_shelf)
        {
            //printf("not full; on shelf\n");
            int temp = shelf[loc];
            int last_loc = 0;
            for(int i=loc; i<shelf_size; i+=1)
            {
                if(shelf[i]!=0)
                {
                    last_loc = i;
                    //printf("last:%d\n",last_loc);
                }
            }
            for(int i=loc;i<shelf_size-1;i+=1)
            {
                shelf[i] = shelf[i+1];
            }
            shelf[last_loc] = temp;
        }
        else
        {
            int has_book = 0;
            for(int i=shelf_size; i>=0; i-=1)
            {
                if(shelf[i]==0)
                {
                    has_book = i;
                    break;
                }
            }
            for(int i=0; i<shelf_size-1; i+=1)
            {
                shelf[i] = shelf[i+1];
            }
            shelf[shelf_size-1] = x;
        }
    }
}
int main()
{
    int x;
    char space;
    int shelf[shelf_size] = {};
    while (scanf("%d",&x)==1)
    {
        // add your code
        take(shelf,x);
        //printf("...\n");
        /*for(int i=0; i<shelf_size; i+=1)
        {
            printf("%d",shelf[i]);
            if(i!=shelf_size-1)
            {
                printf(" ");
            }
        }
        printf("\n");
        */
    }
    for(int i=0; i<shelf_size; i+=1)
    {
        printf("%d",shelf[i]);
        if(i!=shelf_size-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    // output your answer
    return 0;
}
