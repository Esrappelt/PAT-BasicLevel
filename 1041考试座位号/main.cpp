#include<stdio.h>
#include<string.h>
typedef struct
{
    char num[1000];
    int tryno;
    int seat;
}Stu;
void Find(Stu s[],int tryno,int n)
{
    int i;
    for(i = 0;i < n; i++)
    {
    if(tryno == s[i].tryno)
    {
        printf("%s %d\n",s[i].num,s[i].seat);
    }
    }

}
int main()
{
    Stu s[1000];
    char num2[1000];
    int i,n,trynum,a[1000];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s %d%d",&num2,&s[i].tryno,&s[i].seat);
        strcpy(s[i].num,num2);
    }
    scanf("%d", &trynum);
    for(i =0;i < trynum; i++)
    scanf("%d", a +i);
    for(i = 0;i < trynum; i++)
    {
        Find(s,a[i],n);
    }
    return 0;
}
