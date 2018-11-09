#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main()
{
    int n,x,y,dist,id,max_id,min_id,maxv = -inf,minv = inf;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&id,&x,&y);
        dist = x * x + y * y;
        if(dist > maxv)
        {
            maxv = dist;
            max_id = id;
        }
        if(dist < minv)
        {
            minv = dist;
            min_id = id;
        }
    }
    printf("%04d %04d\n",min_id,max_id);
    return 0;
}
