#include <stdio.h>
#include <string.h>
int draw(int num, int index, int country_num, int color_num, int adjacent[][32], int color[])
{
    if (index == country_num)
    {
        for (int i = 0; i < country_num; i++)
        {
            printf("%d\n", color[i]);
        }
        return 1;
    }
    int adjacent1 = -1, adjacent2 = -1;
    int can_color[32] = {};
    for (int i = 0; i < country_num; i++)
    {
        if (i == num)
        {
            continue;
        }
        if (adjacent[num][i] && color[i])
        {
            can_color[color[i]] = 1;
        }
        if (adjacent[num][i] && color[i] == 0)
        {
            adjacent1 = i;
        }
        if (color[i] == 0)
        {
            adjacent2 = i;
        }
    }
    for (int i = 1; i <= color_num; i++)
    {
        if (can_color[i])
        {
            continue;
        }
        color[num] = i;
        if (adjacent1 != -1)
        {
            if (draw(adjacent1, index+1, country_num, color_num, adjacent, color))
            {
                return 1;
            }
        }
        else
        {
            if (draw(adjacent2, index+1, country_num, color_num, adjacent, color))
            {
                return 1;
            }
        }
        color[num] = 0;
    }
    return 0;
}
int main()
{
    int country_num=0, color_num=0, adjacent_num=0;
    scanf("%d %d %d", &country_num, &color_num, &adjacent_num);
    int adjacent[32][32] = {};
    int color[32] = {};
    int x=0, y=0;
    for (int i = 0; i < adjacent_num; i++)
    {
        scanf("%d %d", &x, &y);
        if (x == y)
        {
            continue;
        }
        adjacent[x][y] = adjacent[y][x] = 1;
    }
    int answer = draw(0, 0, country_num, color_num, adjacent, color);
    if (!answer)
    {
        printf("no solution.\n");
    }
    return 0;
}
