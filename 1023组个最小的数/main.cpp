#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i,j,cnt[10],k = 0,k1 = 0,k2 = 0,a[81],c[81],b[81],count = 0;
	for(i = 0; i < 10; i++)
	{
		scanf("%d",cnt + i);
	}
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < cnt[i]; j++)
		{
			if(*(cnt + i) != 0)
			{
				a[k++] = i;
				count++;
			}
		}
	}
	for(i = 0; i < count; i++)
	{
		if(a[i] == 0)
			c[k1++] = a[i];//等于0的放入c数组
		else
			b[k2++] = a[i];//不等于0的放入b数组
	}
	cout << b[0];
	for(i = 0; i < k1; i++)
		cout << c[i];
	for(i = 1; i < k2; i++)
		cout << b[i];
	return 0;
}