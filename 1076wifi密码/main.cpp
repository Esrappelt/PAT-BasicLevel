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
输入第一行给出一个正整数N（<= 100），随后N行，每行按照“编号-答案”的格式给出一道题的4个选项，“T”表示正确选项，“F”表示错误选项。选项间用空格分隔。

输出格式：

在一行中输出wifi密码。

输入样例：
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
输出样例：
13224143
*/

int main()
{
    int N,i,j,index = 0;
    char temp1,temp2;
    scanf("%d",&N);
    getchar();
    int a[1000];
    for(j = 1; j <= N; ++j)
    {
        for(i = 1; i <= 4; ++i)
        {
            scanf("%c-%c",&temp1,&temp2);
            getchar();
            if(temp2 == 'T')
                a[index++] = (int)temp1 - 64;
        }
    }
    for(i = 0; i < index; ++i)
        printf("%d",a[i]);
    printf("\n");
	return 0;
}
