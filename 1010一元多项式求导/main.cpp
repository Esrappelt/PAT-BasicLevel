#include <stdio.h>
#include <iostream>
#include <malloc.h>

using namespace std;
#define Maxsize 100

double Data[Maxsize];
int Exp[Maxsize];

typedef int Datatype;	
typedef struct Node
{
	double data;
	int exp;
	struct Node* next;
}*Linklist,listnode;
void Initlist(Linklist &head)
{
	head = (Linklist)malloc(sizeof(listnode));
	if(head == NULL)
	{
		cout << "内存分配失败!" << endl;
		return;
	}
	head->next = NULL;
}
void CreateList(Linklist &head)
{
	Linklist p = head,q = NULL;
	int i = 0;
	
	cout << "输入多项式的系数data和指数exp:" << endl;
	while(1)
	{
		cin >> Data[i] >> Exp[i];
		if(Exp[i] == 0)
			break;
		i++;
	}
	i = 0;
	while(1)
	{
		q = (Linklist)malloc(sizeof(listnode));
		if(!q)
			exit(-1);
		q->data = Data[i];
		q->exp = Exp[i];
		p->next = q;
		p = q;
		if(q->exp == 0)
			break;
		i++;
	}
	p->next =  NULL;
}



void TraverseList(Linklist head)
{
	Linklist p = head->next;
	int i = 0;
	while(p)
	{
		if(p->next)
		{
			if(p->data && p->exp == 0)
			{
				cout << p->data << " ";
			}
			else if(p->data == 0 && p->exp == 0)
				cout << "0 ";
			else
			{
				cout << p->data << " " << p->exp << " ";
			}
		}
		else
		{
			if(p->data && p->exp == 0)
			{
				cout << p->data;
			}
			else if(p->data == 0 && p->exp == 0)
				cout << "0";
			else
			{
				cout << p->data << " " << p->exp;
			}
		}
		p = p->next;
	}
}

void Derivation(Linklist head,Linklist &L)
{
	Linklist q,p = head,r;
	r = L;
	int i = 0;
	while(p)
	{	
		if(p->exp == 0 || p->data == 0)
		{
			if(p->data == 0)
			{
				p = p->next;
				continue;
			}
			else
			{
				q = (Linklist)malloc(sizeof(listnode));
				if(!q)
					exit(-1);
				q->data = q->exp = 0;
				r->next = q;
				r = q;
				break;
			}
		}
		else
		{
			q = (Linklist)malloc(sizeof(listnode));
			if(!q)
				exit(-1);
			q->data = (p->data ) * (p->exp);
			q->exp = p->exp - 1;
			r->next = q;
			r = q;
		}
		p = p->next;
	}
	r->next = NULL;
	TraverseList(L->next);
}








int main()
{
	Linklist head,L;
	Initlist(head);
	Initlist(L);
	CreateList(head);
	if(Data[0] == 0 && Exp[0] == 0)
		cout << "0 0";
	else
		Derivation(head,L);
	return 0;
}


/*
#include <iostream> 
#include <stdio.h>  
#include <string.h> 
using namespace std;  
struct N{  
    int c;  
    int e;  
}buf[2010], ans[2010];  
  
int main(){  
    int x, y, index = 0, k = 0;  
    while (cin >> x >> y){  
        buf[index].c = x;  
        buf[index++].e = y;  
    }  
    for (int i = 0; i < index; i++){  
        if (buf[i].e){  
            ans[k].c = buf[i].c*buf[i].e;  
            ans[k++].e = buf[i].e - 1;  
        }  
    }  
    if (k == 0){  
        cout << "0 0" << endl;  
        return 0;  
    }  
    for (int i = 0; i < k; i++)  
        cout << ans[i].c << " " << ans[i].e << (i-k+1 ? " ": "\n");  
    return 0;  
}  



 
  
int main()  
{  
    int n, e, flag = 0;  
    while (scanf("%d%d", &n, &e) != EOF)  
    {  
        if( n*e )  
        {  
            if(flag)  
                printf(" ");  
            else  
                flag = 1;  
            printf("%d %d", n*e, e-1);  
        }  
    }  
    if(!flag) printf("0 0");  
      
    return 0;  
}  
*/