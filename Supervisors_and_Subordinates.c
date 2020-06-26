
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};
typedef struct employee Employee;

void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.

    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
Employee *find_root_boss(Employee *set, int n, Employee *e)
{
    for(int i=0; i<n; i+=1)
    {
        if(e->boss_id == set[i].id)
        {
            e = &(set[i]);
        }
    }
    return e;
}
Employee *find_employee_by_name(Employee *set, int n, const char *first, const char *last)
{
    for(int i=0; i<n; i+=1)
    {
        //printf("i:%d\n",i);
        if(strcmp(set[i].first_name, first)==0 && strcmp(set[i].last_name, last)==0)
        {
            //printf("%d",i);
            return &(set[i]);
        }
    }
    return NULL;
}
Employee *find_employee_by_id(Employee *set, const int n, const int id)
{
    for(int i=0; i<n; i+=1)
    {
        if(set[i].id==id)
        {
            return &(set[i]);
        }
    }
    return NULL;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B)
{
    Employee *temp1, *temp2;
    Employee *rootA, *rootB;
    rootA = find_root_boss(set, n, A);
    rootB = find_root_boss(set, n, B);
    if (rootA != rootB)
    {
        return 4;
    }
    temp1 = A, temp2 = B;
    while (temp1 != rootA)
    {
        temp1 = find_employee_by_id(set, n, temp1->boss_id);
        if (temp1 == B)
        {
            return 1;
        }
    }
    while (temp2 != rootB)
    {
        temp2 = find_employee_by_id(set, n, temp2->boss_id);
        if (temp2 == A)
        {
            return 2;
        }
    }
    return 3;
}
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}
int main()
{
    int n, m;
    int i;
    Employee *set = NULL;

    scanf("%d", &n);
    init_storage(&set, n);
    for ( i = 0 ; i < n ; i++ )
    {
        scanf("%d %s %s %d", &(set[i].id), set[i].first_name, set[i].last_name, &(set[i].boss_id));
    }
    char first_name_A[32], first_name_B[32];
    char last_name_A[32], last_name_B[32];
    Employee *A, *B;
    int type;

    scanf("%d", &m);
    for ( i = 0 ; i < m ; i++ )
    {
        scanf("%s %s", first_name_A, last_name_A);
        A = find_employee_by_name(set, n, first_name_A, last_name_A);

        scanf("%s %s", first_name_B, last_name_B);
        B = find_employee_by_name(set, n, first_name_B, last_name_B);

        type = check_relationship(set, n, A, B);

        switch(type)
        {
        case 1:
            printf("subordinate\n");
            break;
        case 2:
            printf("supervisor\n");
            break;
        case 3:
            printf("colleague\n");
            break;
        default:
            printf("unrelated\n");
            break;
        }
    }
    free_storage(&set);
    return 0;
}
