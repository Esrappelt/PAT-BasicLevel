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

int main()
{
    char c;
    int N,i,j;//沙漏个数
    cin >> N >> c;
    int n = 2 * sqrt((N + 1)/2) - 1;//计算出沙漏的总行数
 //   cout << n  << endl;
    int uprow =  (n - 1)/2 + 1;//上面部分所需要的行数
    int downrow = (n - 1)/2;//下面部分所需要的行数
    if(N == 0)
    {
        cout << "1";
        return 0;
    }
    for(i = uprow; i >= 1; --i)
    {
        for(j = 1; j <= (uprow - i); ++j)
            cout << " ";
        for(j = 1; j <= 2 * i - 1; ++j)
            cout << c;
        for(j = 1; j <= (uprow - i); ++j)
            cout << " ";
        cout << endl;
    }
    for(i = 1; i <= downrow; ++i)
    {
        for(j = 1; j <= downrow - i; ++j)
            cout << " ";
        for(j = 1; j <= 2 * i + 1; ++j)
            cout << c;
        for(j = 1; j <= downrow - i; ++j)
            cout << " ";
        cout << endl;
    }
    cout << N + 1 - 2 * uprow * uprow;
	return 0;
}

/*
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；
符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2

*/
