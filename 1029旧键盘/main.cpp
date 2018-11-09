#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。
每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI
*/

void Change(char ans[],int k,char *out,int &m)
{
	int i,j,flag = 1;
	for(i = 0; i < k; i++)
	{
		flag = 1;
		for(j = 0; j < i; j++)
		{
			if(toupper(ans[i]) == toupper(ans[j]))
				flag = 0;//如果遇到前面有相同的元素，则开始去重
		}
		if(flag)//如果前面没有重复的元素,放进新数组
		{
			out[m++] = toupper(ans[i]);
		}
	}
	out[m] = '\0';//记得最后一个元素要变为'\0'
}

int main()
{
	char str1[80];
	char str2[80];
	char ans[80];
	char out1[80],out2[80];
	gets(str1);
	gets(str2);
	int i = 0,j = 0,len1,len2,k = 0,m1 = 0,m2 = 0;
	int flag = 1;
	len1 = strlen(str1);
	len2 = strlen(str2);
	Change(str1,len1,out1,m1);
	Change(str2,len2,out2,m2);
	while(i < m1 && j < m2)
	{
		if(out1[i] == out2[j])
		{
			i++;
			j++;
		}
		else
		{
			ans[k++] = out1[i];
			i++;
		}
	}
	while(i < len1)
	{
		ans[k++] = out1[i];
		i++;
	}
	ans[k] = '\0';
	puts(ans);
	return 0;
}


