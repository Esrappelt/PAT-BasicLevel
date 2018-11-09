#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，
得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，
其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。
*/
char str[100000];
int count[100000];
int main()
{
	gets(str);
	int i,len = strlen(str),sum = 0,count0 = 0,count1 = 0,N;
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a'&& str[i] <= 'z')
			sum += (int)str[i] - 96;
		else if(str[i] >= 'A' && str[i] <= 'Z')	
			sum += (int)str[i] - 64;
	}
	while(sum)
	{
		N = sum%2;
		sum /= 2;
		if(N == 0)
			count0++;
		else
			count1++;
	}
	cout << count0 << " " << count1;
	return 0;
}