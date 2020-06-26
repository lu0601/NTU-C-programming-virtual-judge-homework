#include <stdio.h>  
#include <string.h>  
#define max_str_len 260  
struct Line  
{  
    char lines[max_str_len][max_str_len];  
    int wcounts;  
    int ccounts;  
};  
void winput(struct Line *line, const char w[max_str_len], const int constraint)  
{  
    strcpy(line->lines[line->wcounts], w);  
    line->wcounts +=1;  
    line->ccounts += (strlen(w)+1);  
}  
void words_fusion_print(struct Line *line, const int constraint)  
{  
    int diff = (constraint + 1) - line->ccounts;  
    if ((line->wcounts - 1)==0)  
    {  
        printf("%s", line->lines[0]);  
        for (int i = 0; i < diff; i++)  
        {  
            printf(" ");  
        }  
        printf("\n");  
        return;  
    }  
    int average = diff / (line->wcounts - 1);  
    int remain = diff % (line->wcounts - 1);  
    for (int i = 0; i < line->wcounts; i++)  
    {  
        printf("%s", line->lines[i]);  
        if (i < line->wcounts-1)  
        {  
            for (int j = 0; j < average+ 1; j++)  
            {  
                printf(" ");  
            }  
            if (i<remain)  
            {  
                printf(" ");  
            }  
        }  
    }  
    printf("\n");  
}  
int main()  
{  
    struct Line line;  
    line.ccounts=0, line.wcounts=0;  
    char temp[max_str_len] = {};  
    int constraint=0;  
    scanf("%d", &constraint);  
    while (scanf("%s", temp)==1)  
    {  
        if ( (line.ccounts + strlen(temp)+1) <= (constraint +1))  
        {  
            winput(&line, temp, constraint);  
        }  
        else  
        {  
            words_fusion_print(&line,constraint);  
            line.ccounts=0, line.wcounts=0;  
            winput(&line, temp, constraint);  
        }  
    }  
    words_fusion_print(&line, constraint);  
    return 0;  
}  
