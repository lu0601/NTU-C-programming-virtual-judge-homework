#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int min(int x, int y)
{
    if(x<y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int edit_distance(char *s1, char *s2, int limit, int edit)
{
    if (edit > limit)
    {
        return 1000000;
    }
    if (strcmp(s1, "")==0 && strcmp(s2, "")==0)
    {
        return edit;
    }
    int answer = 1000000, temp;
    if (*s1==*s2)
    {
        temp = edit_distance(s1+1, s2+1, limit, edit);
        answer = min(answer, temp);
    }
    if (*s1!=0)
    {
        temp = edit_distance(s1+1, s2, limit, edit+1);
        answer = min(answer, temp);
    }
    if (*s2!=0)
    {
        temp = edit_distance(s1, s2+1, limit, edit+1);
        answer = min(answer, temp);
    }
    return answer;
}
int main()
{
    char buffer[2048] = {}, *dictionary[101] = {};
    int n=0;
    char *p = buffer;
    while (scanf("%s", p)==1)
    {
        dictionary[n] = p;
        while (*p)
        {
            p+=1;
        }
        p+=1;
        n+=1;
    }
    int id1 = -1, id2 = 0;
    int answer = 1000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i!=j)
            {
                int r = edit_distance(dictionary[i], dictionary[j], answer, 0);
                if (r < answer || (r == answer && i*1000+j < id1*1000+id2))
                {
                    answer = r;
                    id1 = i;
                    id2 = j;
                }
            }
        }
    }
    printf("%d %d %d\n", answer, id1+1, id2+1);
    return 0;
}
