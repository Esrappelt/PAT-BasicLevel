#include <stdio.h>
#include <string.h>

int main()
{

	char str[255];
	char a[255][255];
	gets(str);
	int i = 0,j = 0,k = 0,len = strlen(str);
	for(i = 0; i < len; i++)
	{
		if(str[i] != ' ')
		{
			a[k][j++] = str[i];
		}
		else
		{
			a[k][j] = '\0';
			k++;
			j = 0;
		}
	}
	a[k][j] = '\0';//最后一个一定要记得'\0'
	for(i = k; i >= 0; i--)
	{
		printf("%s",a[i]);
		if(i > 0)
			printf(" ");
	}
	return 0;
}