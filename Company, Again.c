#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
typedef struct employee
{
    char first_name[32];
    char last_name[32];
    struct employee *boss;
} Employee;
typedef struct me
{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} employee;
int relation(Employee *employee1, Employee *employee2)
{
    Employee *temp_employee1 = employee1;
    Employee *temp_employee2 = employee2;
    while(temp_employee1!=temp_employee1->boss)
    {
        if(temp_employee1==employee2)
        {
            return 1;
        }
        temp_employee1 = temp_employee1->boss;
    }
    if(temp_employee1 == employee2)
    {
        return 1;
    }
    while(temp_employee2!=temp_employee2->boss)
    {
        if(temp_employee2==employee1)
        {
            return 2;
        }
        temp_employee2 = temp_employee2->boss;
    }
    if(temp_employee2 == employee1)
    {
        return 2;
    }
    if(temp_employee1==temp_employee2)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
void readName(employee *e)
{
    scanf("%s %s", e->first_name, e->last_name);
}

int nameToIndex(employee *e, employee A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(A[i].first_name, e->first_name) &&
                !strcmp(A[i].last_name, e->last_name))
            return i;
    }
    return -1;
}
int main()
{
    int n, m;
    employee A[32];
    Employee B[32];
    const char out[4][32] = {"subordinate", "supervisor", "colleague", "unrelated"};
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i].id);
            readName(&A[i]);
            scanf("%d", &A[i].boss_id);
        }

        for (int i = 0; i < n; i++)
        {
            strcpy(B[i].first_name, A[i].first_name);
            strcpy(B[i].last_name, A[i].last_name);
            B[i].boss = NULL;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i].boss_id == A[j].id)
                    B[i].boss = &B[j];
            }
        }
        scanf("%d", &m);
        employee x, y;
        for (int i = 0; i < m; i++)
        {
            readName(&x);
            readName(&y);
            int ix = nameToIndex(&x, A, n), iy = nameToIndex(&y, A, n);
            assert(ix != -1);
            assert(iy != -1);
            printf("%d\n", relation(&B[ix], &B[iy]));
        }
    }
    return 0;
}

