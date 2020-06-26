#include <stdio.h>
int main()
{
    int score = 0;
    int score_num=0;
    float sum=0;
    float gpa = 0;
    while(scanf("%d", &score)==1)
    {
        printf("%d ",score);
        sum+=score;
        score_num+=1;
        //printf("%.1f\n", sum);
    }

#ifdef HUNDRED
    while(scanf("%d", &score)==1)
    {
        printf("%d ",score);
        sum+=score;
        score_num+=1;
    }
    printf("score_num = %d\n", score_num);
    float avg = sum/score_num;
    printf("%.1f\n",avg);
#endif // HUNDRED
    /*while(scanf("%d", &score)==1)
    {
        if(score>=90)
        {
            printf("A+ ");
            gpa+=4.3;
            sum+=95;
        }
        else if(score>=85 && score<90)
        {
            printf("A ");
            gpa+=4.0;
            sum+=87;
        }
        else if(score>=80 && score<85)
        {
            printf("A- ");
            gpa+=3.7;
            sum+=82;
        }
        else if(score>=77 && score<80)
        {
            printf("B+ ");
            gpa+=3.3;
            sum+=78;
        }
        else if(score>=73 && score<77)
        {
            printf("B ");
            gpa+=3.0;
            sum+=75;
        }
        else if(score>=70 && score<73)
        {
            printf("B- ");
            gpa+=2.7;
            sum+=70;
        }
        else if(score>=67 && score<70)
        {
            printf("C+ ");
            gpa+=2.3;
            sum+=68;
        }
        else if(score>=63 && score<67)
        {
            printf("C ");
            gpa+=2.0;
            sum+=65;
        }
        else if(score>=60 && score<63)
        {
            printf("C- ");
            gpa+=1.7;
            sum+=60;
        }
        else
        {
            printf("F ");
            sum+=50;
        }
        score_num+=1;
    }
    float avg_gpa = gpa/score_num;
    float avg = sum/score_num;
    printf("%.1f %.1f\n", avg_gpa, avg);*/
#ifdef APLUS
    while(scanf("%d", &score)==1)
    {
        if(score>=90)
        {
            printf("A+ ");
            gpa+=4.3;
            sum+=95;
        }
        else if(score>=85 && score<90)
        {
            printf("A ");
            gpa+=4.0;
            sum+=87;
        }
        else if(score>=80 && score<85)
        {
            printf("A- ");
            gpa+=3.7;
            sum+=82;
        }
        else if(score>=77 && score<80)
        {
            printf("B+ ");
            gpa+=3.3;
            sum+=78;
        }
        else if(score>=73 && score<77)
        {
            printf("B ");
            gpa+=3.0;
            sum+=75;
        }
        else if(score>=70 && score<73)
        {
            printf("B- ");
            gpa+=2.7;
            sum+=70;
        }
        else if(score>=67 && score<70)
        {
            printf("C+ ");
            gpa+=2.3;
            sum+=68;
        }
        else if(score>=63 && score<67)
        {
            printf("C ");
            gpa+=2.0;
            sum+=65;
        }
        else if(score>=60 && score<63)
        {
            printf("C- ");
            gpa+=1.7;
            sum+=60;
        }
        else
        {
            printf("F ");
            sum+=50;
        }
        score_num+=1;
    }
    float avg_gpa = gpa/score_num;
    float avg = sum/score_num;
    printf("%.1f %.1f\n", avg_gpa, avg);
#endif // APLUS
    return 0;
}

// gcc Student_Grades.c -std=c99 -O2 -DHUNDRED -o test1
// gcc Student_Grades.c -std=c99 -O2 -DPLUS -o test2
