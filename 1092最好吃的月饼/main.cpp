#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,c,resm = 0;
    vector<int> res;
    scanf("%d%d",&n,&m);
    int mooncake[1000] = {0};
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d",&c);
            mooncake[j] += c;
        }
    }
    int maxnum = *max_element(mooncake,mooncake+n);
    printf("%d\n",maxnum);
    for(int i = 0; i < n; i++) {
        if(maxnum == mooncake[i]) {
            res.push_back(i+1);
        }
    }
    for(int i = 0; i < res.size(); i++) {
        printf("%d%c",res[i], i == res.size() - 1 ? '\n' : ' ');

    }
    return 0;
}
