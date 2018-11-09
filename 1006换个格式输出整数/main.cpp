#include <stdio.h>
#include <string.h>


int main()
{
	char str[250];
	gets(str);
	int k = 0,a[250],len = strlen(str),i = 0,x,j;
	for(i = len - 1; i >= 0; i--)
	{
		a[k++] = str[i] - '0';
	}
	for(i = k - 1; i >= 0; i--)
	{
		switch(i)
		{
			case 1:
				for(j = 0; j < a[i]; j++)
					printf("S");
				break;
			case 2:
				for(j = 0; j < a[i]; j++)
					printf("B");
				break;
			case 3:
				for(j = 0; j < a[i]; j++)
					printf("Q");
				break;
		}
	}
	for(x = 1; x <= a[0]; x++)
		printf("%d",x);
	return 0;
}