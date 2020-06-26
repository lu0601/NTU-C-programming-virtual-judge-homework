#include <stdio.h>
#include <assert.h>
#define MAXHEAP 100

struct Heap
{
    int ary[MAXHEAP];
    int num;
};
void print_heap(struct Heap *heap)
{
    printf("\n===========\n");
    for(int i=0;i<heap->num;i+=1)
    {
        printf("%d ", heap->ary[i]);
    }
    printf("\n============\n");
}
#define swap(x, y) {int t; t = x, x = y, y = t;}

void initialize(struct Heap *heap)
{
    for(int i=0;i<MAXHEAP;i+=1)
    {
        heap->ary[i]=0;
    }
    heap->num = 0;
}
int removeMin(struct Heap *heap)
{
    int min = heap->ary[0];
    int index=0;
    for(int i=0;i<heap->num;i+=1)
    {
        if(min>heap->ary[i])
        {
            min = heap->ary[i];
            index = i;
        }
    }
    //print_heap(heap);
    for(int i=index;i<heap->num;i+=1)
    {
        heap->ary[i] = heap->ary[i+1];
    }
    heap->num-=1;
    //print_heap(heap);
    return min;
}
void add(struct Heap *heap, int i)
{

    heap->ary[heap->num] = i;
    (heap->num)+=1;
    //print_heap(heap);
}
int isFull(struct Heap *heap)
{
    return heap->num == MAXHEAP;
}
int isEmpty(struct Heap *heap)
{
    return heap->num == 0;
}

int main()
{

    //FILE *fp = fopen("answer.out", "w");
    struct Heap myHeap[10];
    int n;
    while(scanf("%d", &n) == 1)
    {
        int instr;
        int min, i, ret;
        int r;
        r = scanf("%d", &instr);
        assert(r == 1);
        switch(instr)
        {
        case 0:
            initialize(&myHeap[n]);
            break;
        case 1:
            assert(!isEmpty(&myHeap[n]));
            min = removeMin(&myHeap[n]);
            printf( "min = %d\n", min);
            break;
        case 2:
            assert(!isFull(&myHeap[n]));
            r = scanf("%d", &i);
            assert(r == 1);
            add(&myHeap[n], i);
            break;
        case 3:
            ret = isFull(&myHeap[n]);
            if(ret)
                printf("Full\n");
            else
            {
                //fprintf(fp, "End\n");
                printf( "Not Full\n");
            }
            break;
        case 4:
            ret = isEmpty(&myHeap[n]);
            if(ret)
                printf( "Empty\n");
            else
            {
                //fprintf(fp, "end\n");
                printf( "Not Empty\n");
            }
            break;
        }
    }
    return 0;
}
