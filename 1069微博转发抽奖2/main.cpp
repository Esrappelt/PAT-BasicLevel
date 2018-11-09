/*
小明PAT考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔N个人就发出一个红包。
请你编写程序帮助他确定中奖名单。

输入格式：

输入第一行给出三个正整数M（<= 1000）、N和S，
分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从1开始）。
随后M行，顺序给出转发微博的网友的昵称（不超过20个字符、不包含空格回车的非空字符串）。

注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。

输出格式：

按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出“Keep going...”。

*/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef struct 
{
	char name[21];
	int flag;
}Stu;
int main()
{
	Stu s[1001];
	char name[21] = "";
	int M,N,S;
	cin >> M >> N >> S;
	int i,j;
	for(i = 0; i < M; i++)
	{
		scanf("%s",&s[i].name);
		s[i].flag = 0;//没访问的标志为0
	}
	if(S > M)
	{
		printf("Keep going...\n");
		return 0;
	}
	else
	{
		for(i = S - 1; i < M; i += N)
		{
			for(j = 0; j < i; j++)
			{
				if(strcmp(s[i].name,s[j].name) == 0 && s[j].flag == 1)//匹配到与前面相同的,并且访问过的就访问下一个,即i++
					i++;                                              //如果遇到i的下一个相同的,所以没有break,继续j < i		
			}
			cout << s[i].name << endl;
			s[i].flag = 1;//访问过就置为1
		}
	}
	return 0;
}