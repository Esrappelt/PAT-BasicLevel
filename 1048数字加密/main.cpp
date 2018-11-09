
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
本题要求实现一种数字加密方法。
首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；
对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。
*/



int main()
{	
	char str1[101],str2[101],ans[101];
	scanf("%s %s",&str1,&str2);
	int A[100],B[100],sum = 0;
	int lenA = strlen(str1),lenB = strlen(str2),m = 0;
	int i,j,k = 0;
	for(i = lenA - 1,j = 0; i >= 0; i--,j++)
		A[j] = str1[i] - '0';
	for(i = lenB - 1,j = 0; i >= 0; i--,j++)
		B[j] = str2[i] - '0';

/*	for(i = 0; i < lenA; i++)
		cout << A[i] << " ";
	cout << endl;
	for(i = 0; i < lenB; i++)
		cout << B[i] << " ";
	cout << endl;
*/

	i = j = 0;
	while(i < lenA && j < lenB)
	{
		if( (i + 1) % 2 == 1)//如果是奇数位
		{
			sum = A[i] + B[j];
			sum %= 13;
			if(sum >= 10 && sum < 13)
			{
				if(sum == 10)
					ans[k++] = 'J';
				else if(sum == 11)
					ans[k++] = 'Q';
				else if(sum == 12)
					ans[k++] = 'K';
			}
			else
				ans[k++] = sum + '0';
		}
		else if( (i + 1) % 2 == 0)
		{
			sum = B[i] - A[j];
			if(sum >= 0)
				ans[k++] = sum + '0';
			else
				ans[k++] = sum + 10 + '0';
		}
		i++;
		j++;
	}
	if(i < lenA)
	{
		for(m = i; m < lenA; m++)
		{
			
			if((m + 1) % 2 == 1)//奇数
			{
				ans[k++] = A[m] % 13 + '0';
			}
			else//偶数
			{
				sum = A[m];
				if(sum == 0)
					ans[k++] = '0';
				else
				ans[k++] = -sum + 10 + '0';
			}
		}
	}
	else if(j < lenB)
	{
		for(m = j; m < lenB; m++)
			ans[k++] = B[m] + '0';
	}
	ans[k] = '\0';
	for(i = k - 1; i >= 0; i--)
		cout << ans[i];
	cout << endl;
	return 0;
}