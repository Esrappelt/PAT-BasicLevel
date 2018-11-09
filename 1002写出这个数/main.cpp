#include <iostream>
using namespace std;
#define Maxsize 1000
#include <stdio.h>
#include <string.h>

int Sum(int *a,int len)
{
	int i = len - 1,sum = 0,k = 1;
	while(i >= 0)
	{
		sum += a[i];
//		cout << "sum" << k << "=" << sum << " ";
		i--;
		k++;
	}
	return sum;
}

int main()
{
	char a[Maxsize];
	gets(a);
	int i = 0,k = 0,flag = 1,len = strlen(a),b[Maxsize],c[Maxsize],sum;
	while(a[i])
	{
		b[i] = a[i]-'0';
		i++;
	}
	sum = Sum(b,len);
//	cout << "sum = " << sum << endl;
	while(sum > 0)
	{
		c[k] = sum%10;
		sum /= 10;
		k++;
	}
	for(i = k - 1; i >= 0; i--)
	{
		if(i == 0)
			flag = 0;
		switch(c[i])
		{
		case 0:
			if(flag)
				cout << "ling ";
			else
				cout << "ling";
			break;
		case 1:
			if(flag)
				cout << "yi ";
			else
				cout << "yi";
			break;
		case 2:
			if(flag)
				cout << "er ";
			else
				cout << "er";
			break;
		case 3:
			if(flag)
				cout << "san ";
			else
				cout << "san";
			break;
		case 4:
			if(flag)
				cout << "si ";
			else
				cout << "si";
			break;
		case 5:
			if(flag)
				cout << "wu ";
			else
				cout << "wu";
			break;
		case 6:
			if(flag)
				cout << "liu ";
			else
				cout << "liu";
			break;
		case 7:
			if(flag)
				cout << "qi ";
			else
				cout << "qi";
			break;
		case 8:
			if(flag)
				cout << "ba ";
			else
				cout << "ba";
			break;
		case 9:
			if(flag)
				cout << "jiu ";
			else
				cout << "jiu";
			break;
		}

	}
	return 0;
}