#include <stdio.h>
#include <iostream>
using namespace std;

int Gcd(int a,int b)
{
	return a % b == 0 ? b : Gcd(b,a % b);
}

void Yunsuan(int a1,int a2,int b1,int b2)
{
	int deno = b1 * b2,mole1,mole2,mole3,mole4,gcd,m,n;
	int x1,x2,x3,x4;
	int y1,y2,y3,y4;
	mole1 = a1 * b2 + b1 * a2;//相加
	mole2 = a1* b2 - b1 * a2;//相减
	mole3 = a1 * a2;//相乘
	mole4 = b2;//相除
	if(mole1 == 0)//相加
		cout << "0" << endl;
	else
	{
		if(mole1 > 0)
		{
			if( mole1 == deno)
				printf("%d/%d + %d/%d = %d\n",a1,b1,a2,b2,mole1 / deno);
			gcd = Gcd(mole1,deno);//最大公约数
			m = mole1/gcd;
			n = deno/gcd;
			if(m > n)
				printf("%d/%d + %d/%d = %d %d/%d\n",a1,b1,a2,b2,m/n,m%n,n);
			else
				printf("%d/%d + %d/%d = %d/%d\n",a1,b1,a2,b2,m,n);
		}
		else
		{
			mole1 = (-1) * mole1;
			x1 = mole1 / deno;//假分数
			y1 = mole1 % deno;//相加
			if(mole1 == deno)
				printf("%d\n",x1);
			else
			{
				gcd = Gcd(mole1,deno);//最大公约数
				m = mole1/gcd;
				n = deno/gcd;
				if(m > n)
				{
					printf("%d/%d + %d/%d = (-%d %d/%d)\n",a1,a2,b1,b2,x1,m%n,n);
				}
				else
				{
					printf("%d/%d + %d/%d = (-%d/%d)\n",a1,b1,a2,b2,m,n);
				}
			}
		}
	}


	if(mole2 == 0)
		cout << "0" << endl;
	else
	{
		if(mole2 > 0)
		{
			if( mole2 == deno)
				printf("%d/%d + %d/%d = %d\n",a1,b1,a2,b2,mole2 / deno);
			gcd = Gcd(mole1,deno);//最大公约数
			m = mole2/gcd;
			n = deno/gcd;
			if(m > n)
				printf("%d/%d + %d/%d = %d %d/%d\n",a1,b1,a2,b2,m/n,m%n,n);
			else
				printf("%d/%d + %d/%d = (-%d/%d)\n",a1,b1,a2,b2,m,n);
		}
		else
		{
			mole2 = (-1) * mole2;
			x2 = mole2 / deno;//假分数
			y2 = mole2 % deno;//相加
			if(mole2 == deno)
				printf("%d\n",x2);
			else
			{
				gcd = Gcd(mole2,deno);//最大公约数
				m = mole2/gcd;
				n = deno/gcd;
				if(m > n)
				{
					printf("%d/%d + %d/%d = (-%d %d/%d)\n",a1,a2,b1,b2,x1,m%n,n);
				}
				else
				{
					printf("%d/%d + %d/%d = (-%d/%d)\n",a1,b1,a2,b2,m,n);
				}
			}
		}
	}
	if(mole3 == 0)
		cout << "0" << endl;
	else
	{
		if(mole3 > 0)
		{
			if( mole3 == deno)
				printf("%d\n",mole3 / deno);
			gcd = Gcd(mole3,deno);//最大公约数
			m = mole3/gcd;
			n = deno/gcd;
			if(m > n)
				printf("%d %d/%d\n",m/n,m%n,n);
			else
				printf("%d/%d\n",m,n);
		}
		else
		{
			mole3 = (-1) * mole3;
			if(mole3 == deno)
				printf("%d\n",x3);
			else
			{
				gcd = Gcd(mole3,deno);//最大公约数
				m = mole3/gcd;
				n = deno/gcd;
				if(m > n)
				{
					printf("(-%d %d/%d)\n",m/n,m%n,n);
				}
				else
				{
					printf("(-%d/%d)\n",m,n);
				}
			}
		}
	}


	if(mole4 == 0)
		cout << "INF" << endl;
	else
	{
		x4 = a1 * b2;
		y4 = b1 * a2;
		if(x4 < 0 && y4 < 0)
		{
			x4 = (-1) * x4;
			y4 = (-1) * y4;
			gcd = Gcd(x4,y4);//最大公约数
			m = x4/gcd;
			n = y4/gcd;
			if(m > n)
			{
				printf("%d %d/%d\n",m/n,m%n,n);
			}
			else
			{
				printf("%d/%d\n",m,n);
			}
		}
		else if(x4 > 0 && y4 > 0)
		{
			gcd = Gcd(x4,y4);//最大公约数
			m = x4/gcd;
			n = y4/gcd;
			if(m > n)
			{
				printf("%d %d/%d\n",m/n,m%n,n);
			}
			else
			{
				printf("%d/%d\n",m,n);
			}
		}
		else if(x4 < 0 && y4 > 0)
		{
			x4 = (-1) * x4;
			gcd = Gcd(x4,y4);//最大公约数
			m = x4/gcd;
			n = y4/gcd;
			if(m > n)
			{
				printf("(-%d %d/%d)\n",m/n,m%n,n);
			}
			else
			{
				printf("(-%d/%d)\n",m,n);
			}
		}
		else
		{
			y4 = (-1) * y4;
			gcd = Gcd(x4,y4);//最大公约数
			m = x4/gcd;
			n = y4/gcd;
			if(m > n)
			{
				printf("(-%d %d/%d)\n",m/n,m%n,n);
			}
			else
			{
				printf("(-%d/%d)\n",m,n);
			}
		}
	}
}

int main()
{
	int a1,a2,b1,b2;
	scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
	Yunsuan(a1,a2,b1,b2);
	return 0;
}