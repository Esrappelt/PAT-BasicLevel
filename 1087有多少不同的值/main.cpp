#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    set<int> ans;
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i) {
        ans.insert(int(i/2) + int(i/3) + int(i/5));
    }
    printf("%d",ans.size());
    return 0;
}
