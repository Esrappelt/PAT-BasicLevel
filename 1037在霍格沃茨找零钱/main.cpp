#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int g1,s1,k1,g2,s2,k2,g3,s3,k3;
    int sum1,sum2,sum3;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    sum1=(g1*17+s1)*29+k1;
    sum2=(g2*17+s2)*29+k2;
    sum3=sum2-sum1;
    //printf("%d\n",sum3);
    g3=sum3/(17*29);
    s3=(sum3-g3*17*29)/29;
    k3=(sum3-g3*17*29-s3*29);
    if(sum3<0)
    printf("-%d.%d.%d\n",abs(g3),abs(s3),abs(k3));
    else
    printf("%d.%d.%d\n",g3,s3,k3);
    return 0;
}
/*
#include <cstdio>
int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    printf("%d.%d.%d\n",(s1 + s2 + (k1 + k2) / 29) / 17 + g1 + g2,(s1 + s2 + (k1 + k2) / 29) % 17,(k1 + k2) % 29);
    return 0;
}

*/