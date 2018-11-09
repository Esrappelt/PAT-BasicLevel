#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，
而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 10^5]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、
以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
*/


bool bigger(char *a,char *b)//判断a与b的年月关系:a大返回真，b大返回假
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(a[i] > b[i])
			return true;
		else if(a[i] < b[i])
			return false;
	}
	return false;
}
//总结:判断年月份可以直接相应相减********

int main()
{
	char a[20],b[20],old[20],young[20],small[20] = "1814/09/05",bigyear[20] = "2014/09/07";//young代表时间最小的人，old是时间大的人
	int N,valid = 0,i,cnt = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%s %s",&a,&b);//姓名和日期
		if(bigger(b,"1814/09/05") && bigger("2014/09/07",b))
		{
			cnt++;//直接考虑是否满足题目要求
			if(bigger(b,small))//b比small大
			{
				strcpy(small,b);
				strcpy(old,a);//更新姓名
			}
			if(bigger(bigyear,b))//b比bigyear小
			{
				strcpy(bigyear,b);
				strcpy(young,a);
			}
		}
	}
	if(cnt)
	{
		cout << cnt << " " << young << " " << old;
	}
	else
		cout << "0";
	return 0;
}