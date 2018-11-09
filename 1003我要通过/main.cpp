#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
/*
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
*/
#define Maxsize 100
bool flagall[Maxsize] = {true};

int main()
{
	int n,k,i;
	scanf("%d",&n);
	char str[Maxsize];
	getchar();
	for(k = 0; k < n; k++)
	{
		int lenstr,numP = 0,numA = 0,numT = 0;
		int loca = 0,locp = 0,loct = 0;
		gets(str);
		lenstr = strlen(str);
		for(i = 0; i < lenstr; i++)
		{
			if(str[i] == 'P')
			{
				locp = i;
				numP++;
			}
			if(str[i] == 'A')
			{
				loca = i;
				numA++;
			}
			if(str[i] == 'T')
			{
				loct = i;
				numT++;
			}
		}
		if( (numA + numP + numT) != lenstr || numP > 1 || numT > 1 || loct - locp <= 1 || (lenstr - loct - 1) != locp * ( loct - locp - 1) )
		//  1.P A T三个字符个数加起来要等于字符串长度
		//  2.P和T的字符中间必须有一个A,并且P的位置只能在T的位置之前
		//  3.(loct - locp - 1)代表P-T之间的长度,即P-T中间A的个数,locp代表P前面有多少个数，根据题意即为A的个数
		//	4.然后 (lenstr - loct - 1)代表T-lenstr之间的长度,根据题意即为T后面的A的个数
		//  5.根据规律可知:P-T之间每多一个A,P前面和T后面也同时增加一个A,也就是增加两个P,即P前面的A的个数乘上P-T之间的A的个数等于T后面的A的个数
			flagall[k] = false;
		else
			flagall[k] = true;
	}
	for(i = 0; i < n; i++)
	{
		if(flagall[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
