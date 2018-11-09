#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,vector<int>> G;
    int n,m,k,flag;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    while(m--) {
        flag = 1;
        scanf("%d",&k);
        vector<bool> tmp(100000,false);
        vector<int> ans(k);
        for(int i = 0; i < k; ++i) {
            scanf("%d",&ans[i]);
            tmp[ans[i]] = true;
        }
        for(int i = 0; i < k && flag; ++i) {
            int t = ans[i];
            for(int j = 0; j < G[t].size() && flag; ++j) {
                if(tmp[G[t][j]] == true) {
                    flag = 0;
                    printf("No\n");
                }
            }
        }
        if(flag) printf("Yes\n");
    }
    return 0;
}
