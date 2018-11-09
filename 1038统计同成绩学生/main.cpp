#include <stdio.h>
#include <iostream>
using namespace std;

int count[101];//百分制
int grade[100000];

int main()
{
	int N,k,i,score,cnt = 0;
	cin >> N;
	for(i = 0; i < N; i++)
	{
		scanf("%d",&score);
		count[score]++;
	}
	scanf("%d",&k);
	for(i = 0; i < k; i++)
	{
		scanf("%d",&grade[i]);
	}
	for(i = 0; i < k; i++)
	{
		if(i == k - 1)
			cout << count[grade[i]];
		else
			cout << count[grade[i]] << " ";
	}
	return 0;
}

/*
本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第1行给出不超过10^5的正整数N，即学生总人数。
随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
*/