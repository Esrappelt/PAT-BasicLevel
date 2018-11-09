#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。
而在PAT星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。
每个PAT星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是7进制数、第2位是2进制数、第3位是5进制数、第4位是10进制数，等等。
每一位的进制d或者是0（表示十进制）、或者是[2，9]区间内的整数。
理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT星人通常只需要记住前20位就够用了，以后各位默认为10进制。

在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203+415”呢？
我们得首先计算最低位：3+5=8；因为最低位是7进制的，所以我们得到1和1个进位。第2位是：0+1+1（进位）=2；
因为此位是2进制的，所以我们得到0和1个进位。第3位是：2+4+1（进位）=7；因为此位是5进制的，所以我们得到2和1个进位。
第4位是：6+1（进位）=7；因为此位是10进制的，所以我们就得到7。最后我们得到：6203+415=7201。
输入首先在第一行给出一个N位的进制表（0 < N <=20），以回车结束。 随后两行，每行给出一个不超过N位的正的PAT数。

*/

void change(int *a,int len)
{
	int i = 0,j = len - 1;
	while(i < j)
	{
		swap(a[i],a[j]);
		i++;
		j--;
	}
}


void Sum(int dec[],int pat1[],int pat2[],int len)
{
	int i,sum = 0,decimal = 0;
	int k = 0,ans[25];
	for(i = 0; i < len; i++)
	{
		sum = pat1[i] + pat2[i] + decimal;
		if(dec[i] != 0)
		{
			ans[k++] = sum % dec[i];//转换的进制
			decimal = sum / dec[i];//进位
		}
		else
		{
			ans[k++] = sum % 10;
			decimal = sum / 10;
		}
	}
	change(ans,k);
	for(i = 0; i < k; i++)
		if(ans[i] != 0)
			break;
	if(i == k)
	{
		printf("0\n");
		return;
	}
	while(i < k)
	{	
		printf("%d",ans[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int i,j,N,dec[20],pat1[20],pat2[20],len2,len3;
	char str1[20],str2[20],str3[20];
	gets(str1);
	N = strlen(str1);
	fflush(stdin);
	gets(str2);
	len2 = strlen(str2);
	gets(str3);
	len3 = strlen(str3);
	
	for(i = len2 - 1,j = 0; i >= 0; i--,j++)
		dec[j] = str1[i] - '0';
	for(i = len2 - 1,j = 0; i >= 0; i--,j++)
		pat1[j] = str2[i] - '0';
	for(i = len3 - 1,j = 0; i >= 0; i--,j++)
		pat2[j] = str3[i] - '0';
	for(i = len2; i < N; i++)
		pat1[i] = 0;
	for(i = len3; i < N; i++)
		pat2[i] = 0;
	if(N == 1)
	{
		if((pat1[0] + pat2[0]) / dec[0] != 0)
			printf("%d%d\n",(pat1[0] + pat2[0]) % dec[0],(pat1[0] + pat2[0]) / dec[0]);
		else
			printf("%d\n",(pat1[0] + pat2[0]) % dec[0]);
	}
	else
		Sum(dec,pat1,pat2,N);
	return 0;
}