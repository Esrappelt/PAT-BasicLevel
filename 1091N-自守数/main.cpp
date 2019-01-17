#include <bits/stdc++.h>
using namespace std;

int getTail(int tmp,int knum) {
    int num = 0;
    for(int i = 0; tmp && knum; i++,knum--){
        num += (tmp % 10)* pow(10,i);
        tmp /= 10;
    }
    return num;
}

bool selfGuard(int k) {
    int tmpk = k,knum = 0;
    for(; tmpk; tmpk /= 10) {knum++;}
    for(int i = 0; i < 10; i++) {
        int tmp = k * k * i;
        if(k == getTail(tmp,knum)) {
            printf("%d %d\n",i,tmp);
            return true;
        }
    }
    return false;
}
int main()
{
    int m,k;
    scanf("%d",&m);
    while(m--) {
        scanf("%d",&k);
        if(!selfGuard(k)) {
            printf("No\n");
        }
    }
    return 0;
}
