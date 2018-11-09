#include<stdio.h>

typedef struct
{
    int no;
    int num;
    int score;
}Stu;

int main()
{
    Stu s[10000];
    int i,n,j,no = 0,max = 0,sum;
    char c;
    scanf("%d", &n);
    for(i = 0;i < n; i++)
    {
              scanf("%d%c%d%d",&s[i].no,&c,&s[i].num,&s[i].score);
    }
    for(i = 0; i < n; i++)
    {
        sum = s[i].score;
        for(j = i + 1; j < n; j++)
        {
            if(s[i].no == s[j].no)
            {
                sum += s[j].score;
            }
        }
        if(sum > max)
        {
            max = sum;
            no = s[i].no;
        }
     }
    printf("%d %d",no,max);
    return 0;
}
