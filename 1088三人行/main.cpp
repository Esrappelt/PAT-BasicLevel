#include <bits/stdc++.h>
using namespace std;
void print(double para,int m) {
    if(m > para) printf("Gai");
    else if(m == para) printf("Ping");
    else printf("Cong");
}
int main()
{
    int m,x,y,jia,yi,cnt = 0;
    scanf("%d%d%d",&m,&x,&y);
    for(jia = 99; jia >= 10; jia--) {
        yi = (jia%10) * 10 + jia/10;
        double bing = abs(jia - yi) * 1.0 / x;
        if( bing * y == yi)  {
            cnt++;
            printf("%d ",jia);
            print(jia,m);
            cout << ' ';
            print(yi,m);
            cout << ' ';
            print(bing,m);
            return 0;
        }
    }
    if(cnt == 0) printf("No Solution");
    return 0;
}
