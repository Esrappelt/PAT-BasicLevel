#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    double e,a[1000];
    int count=0;
    int D,d;
    int count1=0;
    int count2=0;
    scanf("%d%lf%d",&n,&e,&D);
    for(i=0;i<n;i++)
    {
        count=0;
        scanf("%d",&d);
        for(j=0;j<d;j++)
        {
            scanf("%lf",&a[j]);
            if(a[j]<e)
            {
                count++;
            }
        }
        if(count > d/2)
        {
            count1++;
            if(d > D)
            {
                count1--;
                count2++;
            }
        }
    }
    double ans1=(double)count1/n*100;
    double ans2=(double)count2/n*100;
    printf("%.1f%% %.1f%%",ans1,ans2);
}
