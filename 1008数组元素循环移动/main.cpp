#include <stdio.h>
#include <string.h>
void swap(char *a,char *b)
{
	*a = (*a)^(*b);
	*b = (*a)^(*b);
	*a = (*a)^(*b);
}


void Reverseall(char *a,int p,int q)
{
	for(; q < p;q++,p--)
		swap(&a[q],&a[p]);
}


void ReverPartition(char *a,int len1,int len2)
{
	int lena = strlen(a),i = len1 - 1,j = len2 - 1,k;
	k = len2;
	while(i < j)
	{
		swap(&a[i],&a[j]);
		i++;
		j--;
	}
}

int main()
{
	char a[] = "123456";
	int lena = strlen(a),N,M,len;
	scanf("%d",&M);
	len = strlen(a)-M;
	Reverseall(a,1,len);
	Reverseall(a,len+1,lena);
	Reverseall(a,1,lena);
	puts(a);
	return 0;
}