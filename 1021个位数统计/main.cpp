/*
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，
请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出格式：

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int count[10];
int main()
{
	char num[1000];
	gets(num);
	int i,len = strlen(num);
	for(i = 0; i < len; i++)
	    count[num[i] - '0']++;//统计1-9之间各有多少数字
	for(i = 0; i < 10; i++)
	{
		if(count[i] != 0)
			printf("%d:%d\n",i,count[i]);
	}
	return 0;
}