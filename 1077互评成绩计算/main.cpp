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
在浙大的计算机专业课中，经常有互评分组报告这个环节。
一个组上台介绍自己的工作，其他组在台下为其表现评分。最后这个组的互评成绩是这样计算的：
所有其他组的评分中，去掉一个最高分和一个最低分，剩下的分数取平均分记为 G1；老师给这个组的评分记为 G2。
该组得分为 (G1+G2)/2，最后结果四舍五入后保留整数分。本题就要求你写个程序帮助老师计算每个组的互评成绩。

输入格式：

输入第一行给出两个正整数N（> 3）和M，
分别是分组数和满分，均不超过100。
随后N行，每行给出该组得到的N个分数（均保证为整型范围内的整数），
其中第1个是老师给出的评分，后面 N-1 个是其他组给的评分。
合法的输入应该是[0, M]区间内的整数，若不在合法区间内，则该分数须被忽略。
题目保证老师的评分都是合法的，并且每个组至少会有3个来自同学的合法评分。

输出格式：

为每个组输出其最终得分。每个得分占一行。

输入样例：
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
输出样例：
42
33
41
31
37
39
*/

int main()
{
    int N,M,i,j,grade,G2;
    scanf("%d %d",&N,&M);
    int a[N];//c++11标准
    for(i = 0; i < N; ++i)
    {
        int index = 0,sum = 0,max = 0,min = 51,temp;
        double ave,ans;
        memset(a,0,N);
        scanf("%d",&G2);//G2代表老师的评分
        for(j = 1; j < N; ++j)
        {
            scanf("%d",&grade);
            if(grade >= 0 && grade <= M)
            {
                if(max < grade)
                    max = grade;
                if(min > grade)
                    min = grade;
                a[index++] = grade;
                sum += grade;
            }
        }
        sum -= (max + min);//减去最高和最低
        ave = (double)sum / (index - 2);//平均值
        temp = (ave + G2) / 2;//int值
        ans = (ave + G2)/2;//double值
        if(ans >= (temp + 0.5))
        {
            printf("%d\n",temp + 1);
        }
        else
            printf("%d\n",temp);
    }
	return 0;
}
