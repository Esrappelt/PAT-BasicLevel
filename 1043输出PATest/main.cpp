#include <iostream>
#include <stdio.h>
#include <string.h>



using namespace std;

int main()
{
	char pat[10001],p[10001],a[10001],T[10001],t[10001],e[10001],s[10001];
	gets(pat);
	int len = strlen(pat),i,c1,c2,c3,c4,c5,c6;
	int a1,a2,a3,a4,a5,a6;
	c1 = c2 = c3 = c4 = c5 = c6 = 0;
	a1 = a2 = a3 = a4 = a5 = a6 = 0;
	for(i = 0; i < len; i++)
	{
		if(pat[i] == 'P')
			p[c1++] = pat[i];
		else if(pat[i] == 'A')
			a[c2++] = pat[i];
		else if(pat[i] == 'T')
			T[c3++] = pat[i];
		else if(pat[i] == 'e')
			e[c4++] = pat[i];
		else if('s' == pat[i])
			s[c5++] = pat[i];
		else if('t' == pat[i])
			t[c6++] = pat[i];
		else
			continue;
	}
	for(; a1 < c1 || a2 < c2 || a3 < c3 || a4 < c4 || a5 < c5 || a6 < c6;a1++,a2++,a3++,a4++,a5++,a6++)
	{
		if(a1 < c1)
			cout << p[a1];
		if(a2 < c2)
			cout << a[a2];
		if(a3 < c3)
			cout << T[a3];
		if(a4 < c4)
			cout << e[a4];
		if(a5 < c5)
			cout << s[a5];
		if(a6 < c6)
			cout << t[a6];
	}
	return 0;
}