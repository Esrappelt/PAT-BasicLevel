#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;
int main()
{
	__int64 count = 0,n;
	scanf("%I64d",&n);
	while(n != 1)
	{
		if((n & 1) == 0)
			n = (n >> 1);
		else if((n & 1) == 1)
			n = ((3* n + 1) >> 1);
		count++;
	}
	printf("%I64d",count);
	return 0;
}
