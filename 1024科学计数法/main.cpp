
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <map>
#include <memory.h>
#include <string.h>
using namespace std;


char a[10005];
char b[10005];

int main()
{
	gets(a);
	string ans;
	int i,j,flag1,flag2,temp = 0,k = 0;//temp是指数方
	if(a[0] == '+')
		flag1 = 1;
	else if(a[0] == '-')
		flag1 = 0;

	for(i = 0; i < strlen(a); ++i)
		if(a[i] == 'E')
			break;
	if(a[i+1] == '-')
		flag2 = 1;
	else if(a[i+1] == '+')
		flag2 = 0;


	for(j = i + 2; j < strlen(a); ++j)
		b[k++] = a[j];
	b[k] = '\0';
	temp = atoi(b);
	sscanf(a,"%[^E]",a);//取E前面的字符串
	ans = a;
	int temp2 = ans.length() - 3;//.后面的个数
	if(flag1)
		cout << "";
	else
		cout << "-";
	if(flag2)//左移
	{
		if(temp == 0)
		{
			ans.erase(0,1);
			cout << ans << endl;
		}
		else
		{	
			cout << "0.";
			for(i = 0; i < temp - 1 ; ++i)
			{
				cout << "0";
			}
			ans.erase(0,1);
			ans.erase(1,1);
			cout << ans << endl;
		}
	}
	else
	{
		if(temp == 0)
		{	
			ans.erase(0,1);
			cout << ans << endl;
		}
		else
		{
			for(i = 0; i < temp - temp2; ++i)
			{
				ans = ans + "0";
			}
			cout << ans[1];
			for(i = 3; i < ans.length(); ++i)
				cout << ans[i];
			cout << endl;
		}
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char head,a[10001]= {0};
    int ex = 0;
    scanf("%c%c.%[0-9]E%d",&head,a + 0,a + 1,&ex);//输入拆分
    if (head == '-') printf("-");
    if(ex >= 0)	
    {
        for(int i = 0; i <= ex || a[i] != 0; i++)
        {
            if(i == ex+1) printf(".");
            printf("%c",a[i] == 0 ? '0' : a[i]);
        }
    }
    else
    {
        printf("0.");
        for(int i = 1; i < (-ex); i++)
            printf("0");
        printf("%s",a);
    }
    return 0;
}

*/