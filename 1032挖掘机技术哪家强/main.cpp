#include<stdio.h>
#include <algorithm>
typedef struct
{int score;}Stu;

Stu s[100000];//直接初始化为0

int main()
{

    int i,n,no = 0,max = 0,score,Index;
    scanf("%d", &n);
	scanf("%d%d",&no,&max);
		s[no].score += max;//max初始化为第一个的成绩
    for(i = 1;i < n; i++)
    {
        scanf("%d%d",&Index,&score);
        s[Index].score += score; //对应下标的成绩相加
        if(s[Index].score >= max)//
        {
            max = s[Index].score;//更新最大值
            no = Index;
		}
	}
    printf("%d %d",no,max);
    return 0;
}

//总结：1:直接用对应的下标代表学习的编号，不必重新在结构体里定义一个编号
//      2:一定要初始化数组为0  3:最大值都要初始化为数组的首元素或者其中的一个元素




/*
为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第1行给出不超过105的正整数N，即参赛人数。
随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：

在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。
*/