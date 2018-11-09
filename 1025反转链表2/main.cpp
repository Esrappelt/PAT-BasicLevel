#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <memory.h>
#include <string>
using namespace std;

int n,k;

typedef struct node
{
	int data;
	string address;
	string Nextaddress;
	struct node *next;
}Linknode,*Linklist;

void Init(Linklist &L)
{
	L = new Linknode;
	if(!L)
		return;
	L->next = NULL;
//	cout << "输入头结点的地址:" << endl;
	char ch[6];
	scanf("%s %d%d",&ch,&n,&k);
	L->address = ch;
	L->Nextaddress = "";
}
void create(Linklist &L)
{
	Init(L);
	Linklist p = L,q;
	int i;
	char ad[6],next[6];
	q = new Linknode;
	if(!q)
		return;
	for(i = 0; i < n; i++)
	{	
		q = new Linknode;
		if(!q)
			return;
//		cout << "输入该结点的地址、该结点的值、下一个结点的地址:" << endl;
		scanf("%s %d %s",&ad,&q->data,&next);
		q->address = ad;
		q->Nextaddress = next;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void Traverse(Linklist L)
{
	Linklist p = L->next;
	while(p)
	{
		cout << p->address << " " << p->data << " " << p->Nextaddress << endl;
		p = p->next;
	}
}

//链表排序
void Sort(Linklist &L)
{
	Linklist p = L->next->next,q,pre;
	L->next->next = NULL;
	while(p)
	{
		q = p->next;
		pre = L;
		while(pre->next && pre->next->data < p->data)//找到第一个比p->data大的值 然后插入
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
	p = L;
	while(p->next)
		p = p->next;
	p->Nextaddress = "-1";
}

//反转整个链表
void Reverseall(Linklist &L)
{
	Linklist p = L->next,q;
	L->next = NULL;
	while(p)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

//反转链表
void Reverse(Linklist &L)
{
	Linklist p = L->next,q,pre,r,temp;
	int t = k;
	if(t == 0 || t == 1 )//0、1个结点不用反转
		return;
	while( (t--) && p)
	{
		pre = p;
		p = p->next;
	}
	q = p;
	//pre是p的前驱,q保存了p的后继
	pre->next = NULL;//pre是反转的最后一个结点
	p = temp = L->next;//temp保存第一个结点
	L->next = NULL;
	while(p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	temp->next = q;//q是反转第k个结点之后的不反转的结点
//	cout<< "没改结点值之前:" << endl;
//	Traverse(L);
	Linklist m = L->next,h;
	if(q == NULL)
	{
		while(m->next != q)
		{
			h = m;
			m = m->next;
			h->Nextaddress = m->address;
		}
		Linklist g = L->next;
		while(g->next)
			g = g->next;
		g->Nextaddress = "-1";
	}
	else
	{
		while(m != q)
		{
			h = m;
			m = m->next;
			h->Nextaddress = m->address;
		}
		h->Nextaddress = m->address;
	}
//	cout << "改变地址之后:" << endl;
	Traverse(L);

}









int main()
{
	Linklist L;
	create(L);
//	cout << endl;
//	Traverse(L);
	Sort(L);
//	cout << endl;
//	Traverse(L);
	Reverse(L);
	return 0;
}


/*
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的子链结点的个数。
结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/





/*

  //解法二:精妙的解法 
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int first,n,k,temp,i,j,l;
    int data[100005];
    int next[100005];
    int list[100005];
    int final[100005];
    scanf("%d %d %d", &first, &n, &k);
    for(i=0; i<n; i++)
    {
        scanf("%d", &temp);
        scanf("%d %d",&data[temp],&next[temp]);
    }
    l=0;
    while(first!=-1)
    {
        list[l] = first;
        l++;
        first = next[first];
    }
    for(i=0;i<l;i++)
    {
        final[i] = list[i];
    }
    for(i=0;i<(l-l%k);i++)
    {
        final[i] = list[(i/k)*k+k-i%k-1];
    }
    for(i=0;i<l-1;i++)
    {
        printf("%05d %d %05d\n",final[i],data[final[i]],final[i+1]);
    }
    printf("%05d %d %d\n",final[l-1],data[final[l-1]],-1);
    system("pause");
    return 0;
}
*/