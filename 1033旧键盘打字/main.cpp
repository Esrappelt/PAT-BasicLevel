//#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
//using namespace std;

/*
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。
可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。
题目保证第2行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/

char str[100001],str2[100001];
char ans[100001];
char hash[256];//存放字母的个数
int flag = 1;

void Delete(char *a,char *b)
{
	int ka = 0,kb = 0;
	char *start = b,*end = b;
	char *s = a;
	while(*s)
	{
		++hash[*s];
		s++;
	}
	if(flag)//大写字母能打出来
	{
		while(*end)
		{
			if(hash[*end] == 0)
			{
				start[ka++] = *end;
			}
			end++;
		}
		start[ka] = '\0';//字符串最后一个元素一定要置为'\0'
		if(ka == 0)
			printf("\n");
		else
			puts(start);
	}
	else//不能打出来
	{	
		while(*end)
		{
			if(*end >= 'A' && *end <= 'Z')
			{
				hash[*end] = 1;
			}
			if(hash[*end] == 0)
			{
				ans[kb++] = *end;
			}
			end++;
		}
		ans[kb] = '\0';//字符串最后一个元素一定要置为'\0'
		if(kb == 0)
			printf("\n");
		else
			puts(ans);
	}
}

int main()
{
	int i = 0;
	char c;
	while((c = getchar()) != '\n')
	{
		str[i++] = tolower(c);
		if(c == '+')
			flag = 0;
	}//要删除的字符
	str[i] = '\0';
//	puts(str);
	gets(str2);
	Delete(str,str2);
	return 0;
}


/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    int list[128] = {0}, bad_key = 0, input;

    while ((bad_key = getchar()) != '\n') {
        list[bad_key] = 1;
        list[tolower(bad_key)] = 1; // 将所有坏键赋值为1，如果是字母，相应的大小写字符都要赋值为1
    }
    if (list['+'] == 1) // 检查上档键
        for (int i = 65; i < 91; i++)
            list[i] = 1;
    while ((input = getchar()) != '\n')
        if (list[input] == 0) // 查验字符表，并进行输出
            printf("%c", input);

    return 0;
}
*/