#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
	int J,Y,JH,YH,countJ,countY;
	countJ = countY = 0;
	int n,i;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&JH,&J,&YH,&Y);
		if(J == JH + YH && Y != JH + YH)
			countY++;
		else if(Y == JH + YH && J == JH + YH || Y != JH + YH && J != YH + JH)
			continue;
		else 
			countJ++;

	}
	cout << countJ << " " << countY;
	return 0;
}
