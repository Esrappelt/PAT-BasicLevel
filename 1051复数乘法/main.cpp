#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	double x,y,R1,R2,P1,P2;
	cin >> R1 >> P1 >> R2 >> P2;
	x = R1 * R2 * cos(P1+P2);//R1*R2*cosP1cosP2 - R1 * R2 * sinP1 * sinP2 = R1 * R2 * cos(P1+P2)
	y = R1 * R2 * sin(P1+P2);//R1*R2cosP1sinP2 + R1*R2cosP2sinP1 = R1*R2*sin(P1+P2)
	if(x < 0 && x > -0.005)x = 0;
	if(y < 0 && y > -0.005)y = 0;
	printf("%.2lf%+.2lfi\n",x,y);
	return 0;
}
