/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”
*/

#include<stdio.h>
#define Maxsize 10000
int main()
{
	int n,i,j;
	int cnt = 0,sum1 = 0,max = 0,b1 = 0,d1 = 0,sum2 = 0,c1 = 0;
	int a[Maxsize],sum = 0,b[Maxsize];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 0;i < n; i++)
	{
		j =a[i];
		if(j % 5 == 0 && j % 2 == 0 && j != 0)
		{
			sum +=j;
		}
		else if(j % 5 == 1 )
		{
			c1++;
			if(c1 % 2 != 0)
				sum2 += j;
			else
				sum2 -= j;
		}
		else if(j % 5 == 2)
			cnt++;
		else if(j % 5 == 3)
		{
			sum1 += j;
            d1++;
        }
		else if(j % 5 == 4)
		{
			b[b1++] = j;
		}
	}
	max = b[0];
	for(i = 0; i < b1; i++)
	{
		if(b[i] > max)
			max = b[i];
	}
	if(sum == 0)
		printf("N ");
	else
		printf("%d ",sum);
	if(sum2 == 0)
		printf("N ");
	else
		printf("%d ",sum2);
	if(cnt == 0)
		printf("N ");
	else
		printf("%d ",cnt);
	if(sum1 == 0)
		printf("N ");
	else
		printf("%.1f ",(double)(sum1 / d1));
	if(b1 == 0)
		printf("N");
	else
		printf("%d",max);
	return 0;
}


/*
红眸依深剑眉依浓 [编辑资料] [登出]
主页
题目集
基本信息
题目列表
提交列表
排名
帮助
查看源代码

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
#include <stdio.h>
#include <stdlib.h>
int main()
{
   // freopen("data1.txt","r",stdin);
    int cnt;
    scanf("%d",&cnt);

    int array[5] = {0};

    int i;
    int num,temp,temp1=1,cnt3=0,max = 0;
    int flag1 = 0, flag2 = 0, flag3= 0,flag4 = 0, flag5 = 0;
    for(i = 1; i <= cnt; i++){
        scanf("%d",&num);
        temp = num % 5;
        if(temp == 0 && num % 2 == 0)
            {flag1 = 1; array[0] += num;}
        if(temp == 1) {
            flag2 = 1;
            array[1] += ((temp1 % 2 != 0)? num:(-1*num));
            temp1++;
        }
        if( temp == 2){
            flag3 = 1;
            array[2]++;
        }
        if( temp == 3){
            flag4 = 1;
            cnt3++;
            array[3]+=num;
        }
        if( temp == 4){
            flag5 = 1;
            if(num > max) max = num;
        }
    }

    int h;
    if(flag1) printf("%d ",array[0]); else printf("%c ",'N');
    if(flag2) printf("%d ",array[1]); else printf("%c ",'N');
    if(flag3) printf("%d ",array[2]); else printf("%c ",'N');
    if(flag4) printf("%.1f ",1.0*array[3]/cnt3); else printf("%c ",'N');
    if(flag5) printf("%d",max);else printf("%c",'N');


    return 0;
}
双击代码区域可以查看未格式化的原始代码


查看提交*/