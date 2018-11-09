#include<stdio.h>
int graph[10000][500];
int main()
{
    int N,M,A,B,i,ashv,j;
    scanf("%d%d%d%d%d",&M,&N,&A,&B,&ashv);
    for(i = 0; i < M;i++)
    for(j = 0; j < N; j++)
    scanf("%d", &graph[i][j]);


    for(i = 0; i < M;i++)
    {
        for(j = 0;j < N;j++)
        {
            if(graph[i][j] >= A && graph[i][j] <= B)
            graph[i][j] = ashv;
        }
    }
    for(i = 0; i < M;i++)
    {
        for(j = 0; j < N; j++)
        {
        	if(j == N-1)
        	printf("%03d",graph[i][j]);
            else
            printf("%03d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
