#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>

/*
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：

输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
*/

int count[200];
int a[1000];


char* _strlwr(char* src)  
{  
    while (*src != '\0')  
    {  
        if (*src > 'A' && *src <= 'Z'){  
            *src += 32;  
        }  
        src++;  
    }  
    return src;  
}  



int main()
{
	char str[1000],b[1000],max2;
	gets(str);
	int i,len = strlen(str),k = 0,max1,flag = 0;
	_strlwr(str);
	for(i = 0; i < len; i++)
		count[(int)str[i]]++;//直接用ascll码表下标计数
	for(i = 0; i < len; i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			flag = 1;
		}
	}
	if(flag)
	{
		printf("0");
		return 0;
	}
	for(i = 97; i <= 122; i++)
	{
		if(count[i] != 0)
		{
			a[k] = count[i];
			b[k++] = (char)(i);
		}
	}
	max1 = a[0];
	max2 = b[0];
	for(i = 0; i < k; i++)
	{
		if(a[i] > max1)
		{
			max1 = a[i];
			if(b[i] > max2)
				max2 = b[i];
		}
	}
	cout << max2 << " " << max1 ;
	return 0;
}
