#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/

typedef struct node
{
	char name[10000];
	char number[10000];
	int score;
	struct node *next;
}Listnode,*Linklist;
void InitList(Linklist &stu)
{
	stu = (Linklist)malloc(sizeof(Listnode));
	if(!stu)
		return;
	stu->next = NULL;
}
void CreateList(Linklist &stu,int n)
{
	char name[10000],number[10000];
	int score;
	Linklist q = NULL,p = stu;
	if(n < 0 || n > 100)
	{
		printf("参数错误!");
		return;
	}
	int i = 0;
	for(i = 1; i <= n; i++)
	{
		q = (Linklist)malloc(sizeof(Listnode));
		if(!q)
			return;
		scanf("%s%s%d",&name,&number,&score);
		strcpy(q->name,name);
		strcpy(q->number,number);
		q->score = score;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void Traverse(Linklist stu)
{
	Linklist p = stu->next,q;
	printf("%s %s\n",p->name,p->number);
	while(p)
	{
		q = p;
		p = p->next;
	}
	printf("%s %s\n",q->name,q->number);
}
void Sort(Linklist &stu)
{
	Linklist p = stu->next->next,pre = NULL,q = NULL;
	stu->next->next = NULL;
	while(p)
	{
		q = p->next;
		pre = stu;
		while(pre->next && pre->next->score > p->score)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
	
}
int main()
{
	int n;
	Linklist stu;
	InitList(stu);
	scanf("%d",&n);
	CreateList(stu,n);
	Sort(stu);
	Traverse(stu);
	return 0;
}


