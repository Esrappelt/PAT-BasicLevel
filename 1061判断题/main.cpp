#include<stdio.h>
#include<string.h>

int main()
{
    int N,M,i,j,sum =0;
    int score[100],ans[100];
    int grade[100][100];
    scanf("%d%d", &N,&M);
    for(i = 0;i < M; i++)
    {
        scanf("%d", &score[i]);
    }
    for(i = 0;i < M; i++)
    {
        scanf("%d", &ans[i]);
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            scanf("%d", &grade[i][j]);
        }
    }
    for(i = 0; i < N; i++)
    {
        sum = 0;
        for(j = 0; j < M; j++)
        {
            if(grade[i][j] == ans[j])
            {
                sum += score[j];
            }
        }
        printf("%d\n",sum);
    }
}
