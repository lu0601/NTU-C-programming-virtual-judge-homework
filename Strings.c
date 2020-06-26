#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *x, const void *y)
{
    //printf("cmp.\n");
    char *s1 = *(char **)x;
    //printf("s1\n");
    char *s2 = *(char **)y;
    //printf("s2\n");
    //printf("%s : %s\n", s1, s2);
    return strcmp(s1, s2);
}
int main()
{
    char input[80][40] = {};
    char *temp[80] = {};
    char num=0;
    while(gets(input[num]))
    {
        temp[num] = input[num];
        //printf("temp:%s\n", temp[num]);
        num+=1;
    }
    qsort(temp, num, sizeof(char *), cmp);
    for(int i=0;i<num;i+=1)
    {
        //printf("***\n");
        printf("%s\n", temp[i]);
    }
    return 0;
}
