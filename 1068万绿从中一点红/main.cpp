#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <memory.h>
#include <malloc.h>
using namespace std;



long a[10001][10001];
long TOL;//阀值
int M,N;//N行M列
long ans[1001][1001];

int dx[8] = {1,-1,-1,0,1,-1,0,1};
int dy[8] = {0,0,1,1,1,-1,-1,-1};//判断的8个方向

bool check(int i,int j)
{
	int d,x,y;
	long temp = a[i][j];
	for(d = 0; d < 8; ++d)
	{
		x = i + dx[d%8];
		y = j + dy[d%8];
		if( abs(temp-a[x][y]) <= TOL)//8个方向都必须大于这个值
			return false;
	}
	return true;
}
map<int,int> Is_single;


void color()
{

	int i,j,m = 0,n = 0,k = 0;
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
			if(check(i,j) && Is_single[a[i][j]] == 1)//唯一性
			{
			//	printf("%d %d : %ld\n",i,j,a[i][j]);
				ans[i][j] = a[i][j];
				k++;
				m = i;
				n = j;
			}
			if(k == 2)
				break;
		}
		if(k == 2)
			break;
	}
	if(k == 0)
		printf("Not Exist\n");
	else if(k == 1)
		printf("(%d, %d): %ld\n",n,m,ans[m][n]);
	else
		printf("Not Unique\n");
}

int main()
{
	int i,j;
	scanf("%d %d %ld",&M,&N,&TOL);
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
			scanf("%ld",&a[i][j]);
			++Is_single[a[i][j]];
		}
	}
	color();
	return 0;
}



/*
4 5 9
9 1 99 0
1 1 9 1
1 1 1 1
1 9 1 1
1 1 1 4

8 6 200
0 	     0 	      0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
*/
