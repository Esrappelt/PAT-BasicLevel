#include <iostream>
//#include <algorithm>
#include <stdio.h>
using namespace std;
/*
输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数
；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；
之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：

首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888

*/

typedef struct 
{
	int id;
	int wifeid;
}People;

int flag[99999];
int count[99999];//全部为0
People p[99999];

int main()
{
	int N,i,M,id[10001],tag,temp,cnt = 0,j,k = 0,ans[10001];
	cin >> N;
	for(i = 0; i < N; i++)
	{
		scanf("%d%d",&p[i].id,&p[i].wifeid);
		count[p[i].id] = count[p[i].wifeid] = i + 1;//夫妻和丈夫的值相同
	}
	cin >> M;
	for(i = 0; i < M; i++)
	{
		scanf("%d",&id[i]);//输入要检查的数
	}
	for(i = 0; i < M; i++)
	{
		if(flag[id[i]] == 1)
    		continue;
		temp = count[id[i]];//temp保存count[夫妻或者丈夫]的值,第一个是count[55555] = 3
		tag = 1;
		if(temp == 0)//没有夫妻
		{
			flag[id[i]] = 1;
			ans[k++] = id[i];
			cnt++;
		}
		else	
		{
			for(j = i + 1; j < M; j++)//id[i+1]是44444
			{
				if(flag[id[j]] == 0)//flag[44444] = 0,count[44444] = 2
				{
					if(count[id[j]] == temp)//找到了夫妻
					{
						flag[id[j]] = 1;
						tag = 0;
						break;
					}
				}
				
			}
			if(tag)//没找到
			{
				cnt++;
				ans[k++] = id[i];
			}
		}	
	}
    for (j = 0; j < k - 1; j++)
	{
		for (i = 0; i < k - 1 - j; i++)
        {
            if(ans[i] > ans[i + 1])
            {
                temp = ans[i];
                ans[i] = ans[i + 1];
                ans[i + 1] = temp;
            }
        }
	}
	cout << cnt << endl;
	for(i = 0; i < k; i++)
	{
		if(i == k - 1)
			printf("%05d\n",ans[i]);
		else
			printf("%05d ",ans[i]);
	}
	return 0;
}