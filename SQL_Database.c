#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define max_len  80
#define max_command_len 160
#define max_line_num 20
struct Data
{
    char lastname[max_len];
    char firstname[max_len];
    char ID[max_len];
    int salary;
    int age;
};
struct Command
{
    char line[max_line_num][20];
    int line_count;
};
void judge_field_print(struct Command command, int field_print[], int where_loc)
{
    int j=1;
    for(int i=0; i<8 && j<where_loc; i+=1)
    {
        if(strcmp(command.line[j],"lastname")==0)
        {
            field_print[i] = 1;
        }
        else if(strcmp(command.line[j],"firstname")==0)
        {
            field_print[i] = 2;
        }
        else if(strcmp(command.line[j],"ID")==0)
        {
            field_print[i] = 3;
        }
        else if(strcmp(command.line[j],"salary")==0)
        {
            field_print[i] = 4;
        }
        else if(strcmp(command.line[j],"age")==0)
        {
            field_print[i] = 5;
        }
        j+=1;
    }
}
void judge_field_condition(struct Command command, int *field_condition, int where_loc)
{
    if(strcmp(command.line[where_loc+1],"lastname")==0)
    {
        *field_condition=0;
    }
    else if(strcmp(command.line[where_loc+1], "firstname")==0)
    {
        *field_condition=1;
    }
    else if(strcmp(command.line[where_loc+1], "ID")==0)
    {
        *field_condition=2;
    }
    else if(strcmp(command.line[where_loc+1],"salary")==0)
    {
        *field_condition=3;
    }
    else if(strcmp(command.line[where_loc+1],"age")==0)
    {
        *field_condition=4;
    }
}
void print_field(int field_print[], struct Data data[], int i)
{
    for(int j=0; j<8; j+=1)
    {
        if(field_print[j]==1)
        {
            printf("%s ",data[i].lastname);
        }
        else if(field_print[j]==2)
        {
            printf("%s ",data[i].firstname);
        }
        else if(field_print[j]==3)
        {
            printf("%s ",data[i].ID);
        }
        else if(field_print[j]==4)
        {
            printf("%d ",data[i].salary);
        }
        else if(field_print[j]==5)
        {
            printf("%d ",data[i].age);
        }
    }
}
void print_result(struct Command command, struct Data data[],int data_num)
{
    int where_loc = 0;
    for(int i=0; i<command.line_count; i+=1)
    {
        if(strcmp(command.line[i], "where")==0)
        {
            //printf("****%d\n",i);
            where_loc = i;
            break;
        }
    }
    int field_print[8] = {};
    for(int i=0;i<8;i+=1)
    {
        field_print[i]=0;
    }
    judge_field_print(command, field_print, where_loc);
    int field_condition = 0;
    judge_field_condition(command, &field_condition, where_loc);
    if(field_condition==0)
    {
        if(strcmp(command.line[where_loc+2], "==")==0)
        {
            for(int i=0; i<data_num; i+=1)
            {
                if(strcmp(data[i].lastname,command.line[where_loc+3])==0)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2], "!=")==0)
        {
            for(int i=0; i<data_num; i+=1)
            {
                if(strcmp(data[i].lastname,command.line[where_loc+3])!=0)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
    }
    else if(field_condition==1)
    {
        if(strcmp(command.line[where_loc+2], "==")==0)
        {
            for(int i=0; i<data_num; i+=1)
            {
                //printf("%s\n",data[i].lastname);
                if(strcmp(data[i].firstname,command.line[where_loc+3])==0)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2], "!=")==0)
        {
            for(int i=0; i<data_num; i+=1)
            {
                if(strcmp(data[i].firstname,command.line[where_loc+3])!=0)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
    }
    else if(field_condition==2)
    {
        if(strcmp(command.line[where_loc+2], "==")==0)
        {
            for(int i=0; i<data_num; i+=1)
            {
                if(strcmp(data[i].ID,command.line[where_loc+3])==0)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2], "!=")==0)
        {
            for(int i=0; i<data_num; i+=1)
            {
                if(strcmp(data[i].ID,command.line[where_loc+3])!=0)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
    }
    else if(field_condition==3)
    {
        if(strcmp(command.line[where_loc+2],">")==0)
        {
            int value = atoi(command.line[where_loc+3]);
            for(int i=0; i<data_num; i+=1)
            {
                if(data[i].salary>value)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2],"<")==0)
        {
            int value = atoi(command.line[where_loc+3]);
            for(int i=0; i<data_num; i+=1)
            {
                if(data[i].salary<value)
                {
                    print_field(field_print, data, i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2],"==")==0)
        {
            int value = atoi(command.line[where_loc+3]);
            for(int i=0; i<data_num; i+=1)
            {
                if(data[i].salary==value)
                {
                    print_field(field_print, data, i);
                    printf("\n");
                }
            }
        }
    }
    else if(field_condition==4)
    {
        if(strcmp(command.line[where_loc+2],">")==0)
        {
            int value = atoi(command.line[where_loc+3]);
            for(int i=0; i<data_num; i+=1)
            {
                if(data[i].age>value)
                {
                    print_field(field_print,data,i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2],"<")==0)
        {
            int value = atoi(command.line[where_loc+3]);
            for(int i=0; i<data_num; i+=1)
            {
                if(data[i].age<value)
                {
                    print_field(field_print, data, i);
                    printf("\n");
                }
            }
        }
        else if(strcmp(command.line[where_loc+2],"==")==0)
        {
            int value = atoi(command.line[where_loc+3]);
            //printf("value:%d\n",value);
            for(int i=0; i<data_num; i+=1)
            {
                if(data[i].age==value)
                {
                    //printf("yes!\n");
                    print_field(field_print, data, i);
                    printf("\n");
                }
            }
        }
    }
}
int main()
{
    /*FILE *fp = fopen("test.txt", "w");
    if(fp==NULL)
    {
        printf("cannot open test.txt.\n");
        return 0;
    }*/
    int data_num=0;
    scanf("%d",&data_num);
    struct Data data[data_num+1];
    for(int i=0; i<data_num; i+=1)
    {
        scanf("%s%s%s%d%d",data[i].lastname, data[i].firstname, data[i].ID, &data[i].salary, &data[i].age);
    }
    int command_num=0;
    scanf("%d",&command_num);
    //int max_command_len = 2*max_len;
    struct Command command;
    char temp[max_command_len+1] = {};
    while(gets(temp) && command_num>=0)
    {
        command.line_count=0;
        char *tok;
        tok = strtok(temp, " ");
        while(tok!=NULL)
        {
            //printf("%s\n",tok);
            strcpy(command.line[command.line_count], tok);
            command.line_count+=1;
            tok = strtok(NULL, " ");
        }
        command_num-=1;
        print_result(command,data,data_num);
    }
    return 0;
}
