#include <iostream>
#include <stdio.h>

using namespace std;

/*
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。
*/

int Sort(int *a)
{
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return (a[0]*1000 + a[1]*100 + a[2]*10 + a[3]);
}


int Swap(int *a)
{
	int n,m,k,p;
	k = a[0];
	m = a[1];
	n = a[2];
	p = a[3];
	a[0] = p;
	a[1] = n;
	a[2] = m;
	a[3] = k;
	return (a[0]*1000 + a[1]*100 + a[2]*10 + a[3]);
}




void HeiDong(int n)
{
	int num[4],N = n,a,b,c,d;
	int k1,k2,cnt = 0;
	a = N % 10;
	b = N / 10 % 10;
	c = N /100 % 10;
	d = N / 1000;
	if(a == b && b == c && a == d)
	{
		printf("%04d - %04d = 0000",n,n);
		exit(0);
	}
	while(1)
	{
		cnt++;
		num[0] = N % 10;
		num[1] = N /10 % 10;
		num[2] = N /100 % 10;
		num[3] = N / 1000;
		k1 = Sort(num);
		k2 = Swap(num);
		N = k1 - k2;
		if(k2 < 1000)
		{
			printf("%04d - %04d = %04d\n",k1,k2,N);
		}
		else
			printf("%04d - %04d = %04d\n",k1,k2,N);
		if(k1 - k2 == 6174)
			break;
	}

//	printf("%d",cnt);printf("%02d - %02d = %d\n",k1,k2,N);
}


int main()
{
	int N;
	cin >> N;
	HeiDong(N);
	return 0;
}