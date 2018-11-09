#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 1 << 20

int prime[Maxsize];
int p[Maxsize];

//第一种方法(暴力)已超时
int Prime(int n)
{
	int i,j,k = 3,count = 0,flag = 1;
	for(i = 5; i < n; i++)
	{
		flag = 1;
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			if(flag && i - k == 2)
				count++;
			k = i;
		}
	}
	return count;
}
void prime2(int n)
{
	int vis[10000];
	memset(vis,0,sizeof(vis));
	int m = sqrt(n+0.5);
	for(int i = 2; i <= m; ++i)
	{
		if(!vis[i])
		{
			for(int j = i * i; j <= n; j += i)
				vis[j] = 1;
		}
	}
}

//第二种方法(最高效)
int Isprime(int n)
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
	cout << "素数有:";
	for(i = 0; i < top; i++)
	{	
		if(i % 10 == 0)
			printf("\n");
		cout << prime[i] << " ";
		if(prime[i+1] - prime[i] == 2)
			count++;
	}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("\n满足素数对猜想的数有%d个\n",Isprime(n));
	return 0;
}