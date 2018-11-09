#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int col,i,k;
	int row,j;
	char a;
	scanf("%d%c",&col,&a);
	if((double)col / 2 >= (double)(col / 2 + 0.5))
		row = col / 2 + 1;
	else
		row = col / 2;

	cout << row;
	return 0;
}