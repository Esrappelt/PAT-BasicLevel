#include <stdio.h>
#include <iostream>
using namespace std;

char id[500][500];
int main()
{
	int Right[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[] = {'1','0','X','9','8','7','6','5','4','3','2'};
	int i,j,N,flag1 = 1,flag2 = 1,z,ch,sum = 0,k = 0;
//	printf("输入个数:");
	scanf("%d", &N);
//	printf("输入身份证号码:\n");
	
	for(i = 0; i < N; i++)
	{
		scanf("%s",&id[i]);
	}
	for(i = 0;i < N;i++)
	{
	   	sum = 0;
	   	for(j = 0; j < 17; j++)
		{
			if(id[i][j] >= '0' && id[i][j] <= '9')
			{
				flag1 = 1;
				ch = id[i][j] - '0';
				sum += Right[j] * ch;
			}
			else
			{
				flag1 = 0;
				break;
			}
		}
		if(flag1)
		{
			z = M[sum % 11];
		    if(z != id[i][17])
			{
				flag2 = 0;
				printf("%s\n", id[i]);
			}
		}
		else
			printf("%s\n",id[i]);
	}
	
	if(flag1 && flag2 && N !=0)
		printf("All passed\n");
	return 0;
}
