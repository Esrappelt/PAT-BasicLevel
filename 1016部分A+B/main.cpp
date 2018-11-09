#include<bits/stdc++.h>
using namespace std;


int Sum(char *num,char a)
{
	int len = strlen(num),i,j,cnt = 0,sum = 0,x,flag = 0;
	for(i = len - 1; i >= 0; i--)
	{
		if(num[i] == a)
		{
			flag = 1;
			cnt++;
		}
	}
	x = a - '0';
	j = cnt;
//	sum = x;
	cnt = 1;
	for(i = 0; i < j; i++)
	{
		sum += x * cnt;
		cnt *= 10;

	}
	if(flag)
		return sum;
	else
		return 0;
}



int main()
{
	char num1[100],num2[100],a,b;
	scanf("%s %c %s %c",&num1,&a,&num2,&b);
	cout << Sum(num1,a)+Sum(num2,b) << endl;
	return 0;
}
