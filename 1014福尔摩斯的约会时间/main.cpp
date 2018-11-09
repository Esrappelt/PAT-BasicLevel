#include <cstdio>
#include <cctype>
#include <string>
using namespace std;
int main()
{
	char Engage[4][100],Week[7][10] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int i,flag = 0;
	for(i = 0; i < 4; i++) scanf("%s",&Engage[i]);//初始化二维数组
	for(i = 0,flag = 0; i < strlen(Engage[0]) && i < strlen(Engage[1]); i++)
	{
		if(!flag && Engage[0][i] == Engage[1][i] && Engage[0][i] >= 'A' && Engage[0][i] <= 'G')
		{
			flag = 1;
			printf("%s ",Week[Engage[0][i] - 'A']);
		}
		else if(flag && Engage[0][i] == Engage[1][i] && ( Engage[0][i] >= 'A' && Engage[0][i] <= 'N'|| isdigit(Engage[0][i]) ) )
		{
			printf("%02d:",isdigit(Engage[0][i]) ? Engage[0][i] - '0' : Engage[0][i] - 'A' + 10);
			break;
		}
	}
	for(i = 0; i < strlen(Engage[2]) && i < strlen(Engage[3]);i++)
	{
		if(Engage[2][i] == Engage[3][i] && isalpha(Engage[2][i]))
		{
			printf("%02d",i);
			break;
		}
	}
	return 0;
}