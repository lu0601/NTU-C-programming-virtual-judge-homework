#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max_str_len 80
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
bool consecutive(char *string1, char *string2)
{
    int len1 = strlen(string1), len2 = strlen(string2);
    char temp[max_str_len]= {};
    bool same=false;
    for(int i=1; i<len1; i+=1)
    {

        for(int j=-1; j<=1; j+=2)
        {
            strcpy(temp, string2);
            swap(&temp[i],&temp[i+j]);
            if(strcmp(temp, string1)==0)
            {
                same = true;
                return same;
            }
        }
    }
    return same;
}
void delete_s(char *string, int pos)
{
    char temp[max_str_len] = {};
    if(pos == 0)
    {
        strcpy(temp, string+1);
        strcpy(string, temp);
    }
    else if(pos == strlen(string)-1)
    {
        strncpy(temp, string, pos);
        strcpy(string, temp);
    }
    else
    {
        char temp1[max_str_len] = {};
        char temp2[max_str_len] = {};
        strncpy(temp1, string,pos);
        strcpy(temp2, string+pos+1);
        strcpy(string, temp1);
        strcat(string, temp2);
    }
}
int main()
{
    int pair=0;
    scanf("%d",&pair);
    for(int i=0; i<pair; i+=1)
    {
        bool same=false;
        char string1[max_str_len]= {}, string2[max_str_len]= {};
        scanf("%s%s", string1, string2);
        int len1=strlen(string1), len2 = strlen(string2);
        if(len1 == len2 && consecutive(string1, string2)==1)
        {
            same = true;
        }
        else if(len1 == len2-1)
        {
            char temp[max_str_len] = {};
            for(int i=0; i<len2; i+=1)
            {
                strcpy(temp, string2);
                delete_s(temp,i);
                if(strcmp(temp, string1)==0)
                {
                    same = true;
                }
            }
        }
        else if(len2 == len1-1)
        {
            char temp[max_str_len] = {};
            for(int i=0; i<len1; i+=1)
            {
                strcpy(temp, string1);
                delete_s(temp,i);
                if(strcmp(temp, string2)==0)
                {
                    same = true;
                }
            }
        }
        else if(strcmp(string1, string2)==0)
        {
            same = true;
        }
        if(same == true)
        {
            printf("yes\n");
        }
        else if(same == false)
        {
            printf("no\n");
        }
    }
    return 0;
}
