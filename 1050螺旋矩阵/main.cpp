#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//解法一
int a[10000][10000];
int ans[10000];
int num = 1, m, n, N;
int dx[4] = { 0, 1, 0, -1 };	// 右，下，左，上
int dy[4] = { 1, 0, -1, 0 };

int check(int x, int y)
{
	return (x <= m && y <= n && (!a[x][y]) && x > 0 && y > 0);//小于m行小于n列
}
int cmp(int x,int y)
{return x >y;}

void dfs(int x, int y, int di)
{
	if(num == N)
		return;
	int xx, yy, i;
	for (i = di; i < di + 4; i++)	// 必须每次都循环4次即寻找四个方位
	{
		xx = x + dx[i % 4];
		yy = y + dy[i % 4];
		printf("(x = %d + dx= %d) ,(y = %d + dy = %d) ,xx = %d, yy = %d ",x,dx[i%4],y,dy[i%4],xx,yy);
		if (check(xx, yy))//没有访问过的(没有填充过的)并且参数对的
		{	
			a[xx][yy] = ans[++num];
			printf("a[%d][%d]=%d \n",xx,yy,a[xx][yy]);
			dfs(xx, yy, i % 4);
			num--;
		}
		else
			printf("参数错误或者已经访问过了!\n");
	}
}

int main()
{
	int i, j, k = 0, min = 10001;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &ans[i]);
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i >= j && i * j == N)
			{
				if (abs(i - j) < min)
				{
					min = abs(i - j);
					m = i;
					n = j;
				}
				break;
			}
		}
	}
    sort(ans +1,ans + N +1,cmp);
	for (i = 0; i <= N + 1; i++)
	{
		a[i][0] = -1;
		a[0][i] = -1;
		a[i][N + 1] = -1;
		a[N + 1][i] = -1;
	}// 为它的边界加四边墙
	
	a[1][1] = ans[1];
	for(i = 0; i <= N + 1; ++i)
	{
		for(j = 0; j <= N + 1; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	dfs(1, 1, 0);
	cout << endl;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; ++j)
		{
			if(j == n)
				printf("%d", a[i][j]);
			else
				printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*

//解法二:
#include <iostream> 
#include <algorithm>
#include <cmath> 
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std; 

int compare(int a,int b) { return a > b; }


int A[10000];
int T[10000][10000];

void solve()
{
	int i,j,k,N;
	cin >> N; 
	for(i = 0; i < N; i++)
	{ 
		cin >> A[i]; 
	}
	sort(A, A + N, compare); //以sqrt（n）向下寻找最大的n 
	int m, n = sqrt(N);
	while(N % n)
		n --; 
	m = N / n; 
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, di = 0; 
	i = 0;
	j = 0;
	k = 0; 
	do
	{ 
		T[i][j] = A[k++]; //相当于置为访问,填充数字
		int ni = i + dx[di], nj = j + dy[di];//依次是1.x不变(y+1) 2.x+1 然后 y 不变  3.x 不变 y-1 4.最后(x-1)  y不变    
		if(ni < 0 || ni >= m || nj < 0 || nj >= n || T[ni][nj])//如果参数不对  或者已经填过数字了  那就继续找另一个方位
			di = (di + 1) % 4;//有4个方位
		i += dx[di];//
		j += dy[di];//
	}while(k < N); 

	for(i = 0; i < m; i ++)
	{	
		for(int j = 0; j < n; j ++)
		{	
			cout << T[i][j];
			if(j + 1 < n) cout << " "; 
		} 
		cout << endl;
	} 
} 
int main() 
{
	solve(); 
	return 0; 
}
*/