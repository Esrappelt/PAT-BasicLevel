#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


/*
在数学中，矩阵的“谱半径”是指其特征值的模集合的上确界。换言之，对于给定的n个复数空间的特征值{a1+b1i, ..., an+bni}，它们的模为实部与虚部的平方和的开方，而“谱半径”就是最大模。

现在给定一些复数空间的特征值，请你计算并输出这些特征值的谱半径。

输入格式：

输入第一行给出正整数N（<= 10000）是输入的特征值的个数。随后N行，每行给出1个特征值的实部和虚部，其间以空格分隔。注意：题目保证实部和虚部均为绝对值不超过1000的整数。

输出格式：

在一行中输出谱半径，四舍五入保留小数点后2位。
*/

int main()
{
	int N,real,imagine,i;
	double max = 0,sum,r;
	cin >> N;
	for(i = 0 ; i < N; i++)
	{
		scanf("%d%d",&real,&imagine);
		sum = pow(real,2) + pow(imagine,2);
		r = (double)sqrt(sum);
		if(r > max)
			max = r;
	}
	printf("%.2f",max);
	return 0;
}