#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long a[1000000];
void Array(long N,long *a,long p)
{
	long i,j;
	long len = 1;
	for(i = 0; i < N; i++)
	{
		for(j = len + i; j < N; j++)
		{
			if(a[j] > a[i] * p)
				break;
			if(j - i + 1 > len)
				len = j - i + 1;
		}
	}
	cout << len;
}

int main()
{
	long N,p,i;

	scanf("%ld%ld",&N,&p);
	if(N <= 0 || p <= 0)
		printf("0");
	else
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+N);
		Array(N,a,p);
	}
	return 0;
}
