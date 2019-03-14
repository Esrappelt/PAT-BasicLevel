#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> wolf(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&wolf[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            vector<int> flag(n+1,1),lier;
            flag[i] = flag[j] = -1;
            for(int k = 1; k <= n; k++) {
                if(flag[abs(wolf[k])] * wolf[k] < 0){
                    lier.push_back(k);
                }
            }
            if(lier.size() == 2 && flag[lier[0]] * flag[lier[1]] < 0){
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
