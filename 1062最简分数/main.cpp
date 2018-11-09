#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a,int b){return (a%b == 0)? b:gcd(b,a%b);}


int main()
{
	int i,x1,y1,x2,y2,k,flag = 1,tag = 0;
	int a[1000],m = 0;
	scanf("%d/%d %d/%d %d",&x1,&y1,&x2,&y2,&k);
	if(x1 * y2 > x2 * y1)
		flag = 0;
	else if(x1 * y2 < x2 * y1)
		flag = 1;
	for(i = 1; i < k; i++)
	{
		if(flag)
		{
			if(x1 * k < y1 * i && y2 * i < x2 * k)
			{
				if(gcd(i,k) == 1)
				{
			//		cout << i << endl;
					a[m++] = i;
				}
			}
		}
		else
		{
			if(x2 * k < y2 * i && y1 * i < x1 * k)
			{
				if(gcd(i,k) == 1)
				{
			//		cout << i << endl;
					a[m++] = i;
				}
			}
		}

	}
	for(i = 0; i < m; i++)
	{
		if(i == m - 1)
			printf("%d/%d",a[i],k);
		else
			printf("%d/%d ",a[i],k);
	}
	return 0;
}
