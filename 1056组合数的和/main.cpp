#include <iostream>

#include <stdio.h>
using namespace std;





int main()
{
	int N,i,j,temp = 0,k = 0,sum = 0;
	int a[11],b[100];
	cout << "输入个数:" << endl;
	cin >> N;
	cout << "输入数字:" << endl;
	for(i = 0; i < N; i++)
		cin >> a[i];
	for(i = 0; i < N; i++)
	{	
		temp = a[i];
		for(j = 0; j < N; j++)
		{
			if(a[j] != temp)
				b[k++] = a[j] + 10 * temp;
		}
	}
	for(i = 0; i < k; i++)
	{
		cout << b[i] << " ";
	}
	cout << "他们的和是:" << endl;
	for(i = 0; i < k; i++)
		sum += b[i];
	cout << sum;
	return 0;
}