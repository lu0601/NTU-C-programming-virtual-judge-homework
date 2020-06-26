#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define max_str_len 128
bool yes(char *input)
{
    if(strcmp(input, "of")!=0 && strcmp(input, "and")!=0 && strcmp(input, "the")!=0 && strcmp(input, "at")!=0 && strcmp(input, "of.")!=0 && strcmp(input, "and.")!=0 && strcmp(input, "the.")!=0 && strcmp(input, "at.")!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    char input[max_str_len] = {};
    char abb[max_str_len] = {};
    while(scanf("%s",input)==1)
    {
        char ans[max_str_len] = {};
        bool output = false;
        int input_len = strlen(input);
        for(int i=0; i<input_len; i+=1)
        {
            if(input[i]=='.')
            {
                output = true;
            }
        }
        if(yes(input))
        {
            char upper = ' ';
            upper = toupper(input[0]);
            char temp[2] = {};
            temp[0] = upper;
            temp[1] = '\0';
            //printf("temp = %s\n",temp);
            if(output == true)
            {
                strcat(abb, temp);
                printf("%s\n",abb);
                //printf("\n");
                char zero[max_str_len] = {};
                strcpy(abb,zero);
            }
            else
            {
                strcat(abb, temp);
                strcpy(ans, abb);
            }
        }
        else
        {
            if(output==true)
            {
                printf("%s\n",abb);
                char zero[max_str_len] = {};
                strcpy(abb, zero);
            }

        }
    }
    return 0;
}
