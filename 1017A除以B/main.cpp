#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char c;
	int a[1000];
	int carry = 0,len,i = 0,b;//carry是保存上一位的余数，并更新到下一位
	while(( c = getchar() ) != '\n' )
		a[i++] = c - '0';//直接转化为整型数组
	len = i;
	scanf("%d", &b);//b是除数
	for(i = 0; i < len; i++)
	{
		if(i != 0 || a[i] / b != 0)
		{
			printf("%d",(10 * carry + a[i]) / b);//10*余数+当前数再除以b就是商,carry== 0时就是a[i]/b
		}
		carry = (10 * carry + a[i]) % b;//直接取余得到余数
	}
	if(len == 1 || a[0] / b == 0)//只有1个元素  或者是第一个元素除以b为0
		printf(" %d",carry);//直接输出余数	
	return 0;
}