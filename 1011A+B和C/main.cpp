#include <iostream>
#include <stdio.h>
#define Maxsize 1000
using namespace std;

int main()
{
	bool a[Maxsize];
	int n,i,k = 0;
	__int64 A,B,C;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%I64d %I64d %I64d",&A,&B,&C);
		if(A + B > C)
			a[k++] = true;
		else
			a[k++] = false;
	}
	for(i = 0; i < k; i++)
	{
		if(a[i])
			printf("Case #%d:true\n",i + 1);
		else
			printf("Case #%d:false\n",i + 1);
	}
	
	
	return 0;
}