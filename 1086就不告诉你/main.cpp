#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    int a,b,c,i;
    scanf("%d%d",&a,&b);
    c = a * b;
    if(c == 0) {
        printf("0");
        return 0;
    }
    while(c) {
        ans.push_back(c%10);
        c /= 10;
    }
    for(i = 0; i < ans.size(); ++i) if(ans[i]) break;
    while(i < ans.size()) {
        printf("%d",ans[i]);
        i++;
    }
    return 0;
}
