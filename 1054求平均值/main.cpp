#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
本题的基本要求非常简单：给定N个实数，计算它们的平均值。
但复杂的是有些输入数据可能是非法的。
一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。
最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。
如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
*/

int main()
{
	int N,flag,cnt = 0,i,j;
	char str1[10000],str2[10000];
	double sum = 0,temp;
//	gets(str);
//	sscanf(str,"%lf",&sum);//读str这个字符串,自动获取str里的东西放入sum
//	sprintf(str2,"%.2lf",sum);//按照.2lf格式放入str2中
//	puts(str2);//然后输出str2
	scanf("%d",&N);
	fflush(stdin);
	for(i = 0; i < N; i++)
	{
		scanf("%s ",&str1);
		sscanf(str1,"%lf",&temp);//读str1这个字符串,自动获取str里的东西放入temp
		sprintf(str2,"%.2lf",temp);//按照.2lf格式放入str2中
		flag = 0;
		for(j = 0; j < strlen(str1); j++)
		{
			if(str1[j] != str2[j])
				flag = 1;
		}
		if(flag || temp < -1000 || temp > 1000)
		{
			printf("ERROR: %s is not a legal number\n",str1);
		}
		else
		{
			sum += temp;
			cnt++;
		}
	}
	if(cnt == 1)
	{
		printf("The average of 1 number is %.2lf\n",sum);
	}
	else if(cnt > 1)
	{
		printf("The average of %d numbers is %.2lf\n",cnt,sum / cnt);
	}
	else
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	return 0;
}
