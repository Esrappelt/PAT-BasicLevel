#include <stdio.h>
#define Maxsize 1 << 20
#define INF 1000000
int count = 0;
int prime[Maxsize];
int p[Maxsize];
void Prime(int n)
{
	int i,j,count = 0,flag = 1,top = 0;
	for(i = 2; i <= n; i++)
	{
		if(p[i] == 0)//这里先判断是不是素数
		{
			prime[top++] = i;
		}
		for(j = 0; j < top && i * prime[j] <= n; j++)
		{
			p[i*prime[j]] = 1;//已经不是素数了
			if(i % prime[j] == 0)//能够整除就不是素数了，一定记住是这里才开始判断是不是素数,在进行筛选
				break;
		}
	}
}
int main()
{
	int m,n,i;
	scanf("%d%d",&m,&n);
	Prime(INF);
	for(i = m; i <= n; i++)
	{
		printf("%d",prime[i-1]);
        if ((i - m + 1) % 10 == 0 || i == n)
            printf("\n");
		else
            printf(" ");
    }
	return 0;
}