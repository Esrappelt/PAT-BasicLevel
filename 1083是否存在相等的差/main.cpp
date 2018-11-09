#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,temp;
    map<int,int> ans;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d",&temp);
        ans[abs(temp - i)]++;
    }
    for(auto it = ans.rbegin(); it != ans.rend(); ++it) {
        if(it->second >= 2) {
            printf("%d %d\n",it->first,it->second);
        }
    }
    return 0;
}
