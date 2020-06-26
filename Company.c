#include <stdio.h>
#include <string.h>
#define max_employee 32
struct Employee
{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
void init(struct Employee employee[], int employee_num)
{
    for(int i=0; i<employee_num; i+=1)
    {
        employee[i].id=0;
        strcpy(employee[i].first_name, "");
        strcpy(employee[i].last_name, "");
        employee[i].boss_id=0;
        //printf("%d %s %s %d\n",employee[i].id, employee[i].first_name, employee[i].last_name, employee[i].boss_id);
    }
}
int findindex(const struct Employee employee_find, const struct Employee employee[], const int employee_num)
{
    for(int i=0;i<employee_num;i+=1)
    {
        if(strcmp(employee_find.first_name, employee[i].first_name)==0 && strcmp(employee_find.last_name, employee[i].last_name)==0)
        {
            //printf("i:%d\n",i);
            return i;
        }
    }
    return -1;
}
void build_relation(const int employee_num, struct Employee employee[],int parent[])
{
    for(int i=0;i<employee_num;i+=1)
    {
        parent[i] = i;
    }
    for(int i=0;i<employee_num;i+=1)
    {
        for(int j=0;j<employee_num;j+=1)
        {
            if(i!=j)
            {
                if(employee[i].boss_id == employee[j].id)
                {
                    parent[i] = j;
                }
            }
        }
    }
}
int find_relation(const int index1, const int index2, const int parent[])
{
    int temp1 = parent[index1], temp2 = parent[index2];
    while(temp1!=parent[temp1])
    {
        if(temp1==index2)
        {
            return 0;
        }
        temp1 = parent[temp1];
    }
    if(temp1 == index2)
    {
        return 0;
    }
    while(temp2!=parent[temp2])
    {
        if(temp2 == index1)
        {
            return 1;
        }
        temp2 = parent[temp2];
    }
    if(temp2==index1)
    {
        return 1;
    }
    if(temp2 == temp1)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int main()
{
    struct Employee employee[max_employee];
    char answer[4][15] = {"subordinate", "supervisor", "colleague", "unrelated"};
    int employee_num=0;
    scanf("%d",&employee_num);
    init(employee,employee_num);
    for(int i=0; i<employee_num; i+=1)
    {
        scanf("%d", &employee[i].id);
        scanf("%s%s", employee[i].first_name, employee[i].last_name);
        scanf("%d", &employee[i].boss_id);
        //printf("***%d %s %s %d", employee[i].id, employee[i].first_name, employee[i].last_name,employee[i].boss_id);
        //printf("\n");
    }
    int parent[32] = {};
    build_relation(employee_num, employee, parent);
    for(int i=0;i<32;i+=1)
    {
        printf("%d ",parent[i]);
    }
    printf("\n");
    int relation_num=0;
    scanf("%d",&relation_num);
    struct Employee employee1, employee2;
    for(int i=0;i<relation_num;i+=1)
    {
        scanf("%s%s",employee1.first_name, employee1.last_name);
        scanf("%s%s", employee2.first_name, employee2.last_name);
        //printf("%s %s %s %s\n", employee1.first_name, employee1.last_name,employee2.first_name, employee2.last_name);
        int index1 = findindex(employee1,employee,employee_num);
        int index2 = findindex(employee2,employee,employee_num);
        if(index1==-1 || index2==-1)
        {
            printf("%s\n",answer[3]);
        }
        else
        {
            printf("%s\n",answer[find_relation(index1, index2, parent)]);
        }
    }
    return 0;
}
