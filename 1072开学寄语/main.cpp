#include<stdio.h>
typedef struct{
    int no;
    char name[5];
}Student;
int main()
{
    int N,M,i,j,k,r,h,cnt1,cnt2,flag;
    r=h=cnt1=flag=cnt2=0;
    Student s;
    int check[11],ans2[11];
    char ans1[5];
//    printf("输入学生人数和检查数\n");
    scanf("%d%d",&M,&N);
//    printf("输入检查的数\n");
    for(i=0;i< N ;i++)
    {
        scanf("%d",&check[i]);
    }
    for(i =0;i < M ;i++)
    {
        flag=0;
        h=0;
 //       printf("输入名字和有多少个包裹\n");
        scanf("%s %d",&s.name,&k);
        for(j = 0;j < k;j++)
        {
//        	printf("输入编号\n");
            scanf("%d",&s.no);
            for(r=0;r< N;r++)
            {
                if(check[r]==s.no)
                {
                    ans2[h++]=s.no;
                    flag =1;
                }
            }
        }
            if(flag)
            {
            	cnt1++;
                printf("%s: ",s.name);
                for(r=0;r< h;r++)
                {
                    if(r==h-1)
                    printf("%04d",ans2[r]);
                    else
                    printf("%04d ",ans2[r]);
                }
                printf("\n");
            }
            cnt2 += h;
        }
    printf("%d %d\n",cnt1,cnt2);
    return 0;
}
