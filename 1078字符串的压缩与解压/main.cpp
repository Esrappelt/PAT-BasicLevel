#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <malloc.h>
#include <memory.h>
using namespace std;
/*
文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。

解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。

本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

输入格式：

输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过1000个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过1MB。

输出格式：

根据要求压缩或解压字符串，并在一行中输出结果。

输入样例 1：
C
TTTTThhiiiis isssss a   tesssst CAaaa as
输出样例 1：
5T2h4is i5s a3 te4st CA3a as
输入样例 2：
D
5T2h4is i5s a3 te4st CA3a as10Z
输出样例 2：
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*/
void change1(string a)
{
    char temp;
    int i,j,cnt;
    for(i = 0; i < a.length(); ++i)
    {
        temp = a[i];
        cnt = 1;
        while(a[i+1] == temp)
        {
            cnt++;
            i++;
        }
        if(cnt == 1)
            printf("%c",temp);
        else
            printf("%d%c",cnt,temp);
    }
}

void change2(string a)
{
    int i,j,cnt = 0,c = 0,k = 0;
    for(i = 0; i < a.length(); ++i)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            c = cnt = 0,k = i;
            while(a[i] >= '0' && a[i] <= '9')
            {
                i++;
                c++;//有c位数
            }
            for(j = k; j <= k + c - 1; ++j)
                cnt += (a[j] - '0') * pow(10,c+k-j-1);
            for(j = 0; j < cnt; ++j)
                printf("%c",a[i]);
        }
        else
            printf("%c",a[i]);
    }
}


int main()
{
    int i,j,k;
    char c;
    string a;
    scanf("%c",&c);
    getchar();
    getline(cin,a,'\n');
    if(c == 'C')
        change1(a);
    else
        change2(a);
    printf("\n");
	return 0;
}
