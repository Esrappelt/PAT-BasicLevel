#include <iostream>
#include <stdio.h>
using namespace std;
/*
输入第1行给出正整数N（<=105），即双方交锋的次数
。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，
第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

*/
int A[256],B[256];
int main()
{
	char a,b;
	int n,i,j;
	int awin = 0,ping = 0,afail = 0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;//a是甲,//b是乙
		if(a == b)
		{
			ping++;
		}
		else
		{
			if(a == 'C')
			{
				if(b == 'J')
				{
					awin++;
					A[67]++;
				}
				else if(b == 'B')
				{
					afail++;
					B[66]++;		
				}
			}
			else if(a == 'J')
			{
				if(b == 'B')
				{
					awin++;
					A[74]++;
				}
				else if(b == 'C')
				{
					afail++;
					B[67]++;
				}
			}
			else if(a == 'B')
			{
				if(b == 'C')
				{
					awin++;
					A[66]++;
				}
				else if(b == 'J')
				{
					afail++;
					B[74]++;
				}
			}
		}
	}
	if(A[67] == A[74] && A[74] == A[66])
		i = 66;
	else
	{
		i = A[67] >= A[74] ? 67:74;
		i = A[i] > A[66] ? i : 66;
	}
	if(B[67] == B[74] && B[74] == B[66])
		j = 66;
	else
	{
		j = B[67] >= B[74] ? 67:74;
		j = B[j] > B[66] ? j : 66;
	}
	printf("%d %d %d\n",awin,ping,afail);
	printf("%d %d %d\n",afail,ping,awin);
	printf("%c %c\n",i,j);
	return 0;
}

