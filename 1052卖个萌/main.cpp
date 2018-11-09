#include <stdio.h>
#include <iostream>
using namespace std;

/*
萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。
题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。

之后一行给出一个正整数K，为用户请求的个数。
随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。
*/
char hand[20][20],eye[20][20],mouth[20][20];

int Get(char ans[][20])
{
	char c;
	int i,j;
	i = j = 0;
	while((c = getchar()) != '\n')
	{
		if(c == '[')
		{
			while( (c= getchar()) != ']')
			{
				if(c == '\n')
					return i - 1;
				ans[i][j++] = c;
			}
			ans[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	return i - 1;//个数
}



int main()
{
	int i,n,x1,x2,x3,a,b,c,d,e;
	x1 = Get(hand);
	x2 = Get(eye);
	x3 = Get(mouth);
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(a <= 0|| b <= 0 || c <= 0 || d <= 0 || e <= 0)
			printf("Are you kidding me? @\\/@\n");
		else if(a > x1 + 1 || b > x2 + 1|| c >x3 + 1|| d > x2 + 1|| e > x1 + 1)
			printf("Are you kidding me? @\\/@\n");
		else
			printf("%s(%s%s%s)%s\n",hand[a-1],eye[b-1],mouth[c-1],eye[d-1],hand[e-1]);//下标减一
	}
	return 0;
}

