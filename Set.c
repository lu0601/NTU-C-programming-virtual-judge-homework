#include <stdio.h>
typedef unsigned long long Set;
void init(Set *set)
{
    *set=0;
}
void add(Set *set, int i)
{
    *set|=1LL<<i;
}
void has(Set set, int i)
{
    printf("**%d\n",set>>i);
    if((set>>i)&1)
    {

        printf("set has %d\n",i);
    }
    else
    {
        printf("set does not have %d\n",i);
    }
}
Set setUnion(Set a, Set b)
{
    return a|b;
}
Set setIntersect(Set a, Set b)
{
    return a&b;
}
Set setDifference(Set a, Set b)
{
    return a^b;
}
int main()
{
    char action = ' ';
    Set set[2000] = {};
    while(scanf("%c",&action)==1)
    {
        if(action == 'Z')
        {
            int set_num=0;
            scanf("%d",&set_num);
            init(&set[set_num]);
        }
        else if(action == 'A')
        {
            int add_num =0, set_num=0;
            scanf("%d%d",&set_num, &add_num);
            add(&set[set_num], add_num);
        }
        else if(action == 'H')
        {
            int has_num=0,set_num=0;
            scanf("%d%d",&set_num, &has_num);
            has(set[set_num],has_num);
        }
        else if(action == 'U')
        {
            int union_num=0, set1_num=0, set2_num=0;
            scanf("%d%d%d",&union_num, &set1_num, &set2_num);
            set[union_num] = setUnion(set[set1_num], set[set2_num]);
            //printf("u:%lld\n",set[union_num]);
        }
        else if(action == 'I')
        {
            int inter_num=0, set1_num=0, set2_num=0;
            scanf("%d%d%d",&inter_num,&set1_num, &set2_num);
            set[inter_num] = setIntersect(set[set1_num], set[set2_num]);
        }
        else if(action == 'D')
        {
            int dif_num=0,set1_num=0,set2_num=0;
            scanf("%d%d%d", &dif_num,&set1_num, &set2_num);
            set[dif_num] = setDifference(set[set1_num], set[set2_num]);
        }
    }
    printf("END\n");
    return 0;
}
