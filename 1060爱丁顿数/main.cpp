#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <malloc.h>
#include <memory.h>
using namespace std;

bool cmp(const int &x,const int &y)
{
    return x > y;
}

int main()
{
    int i,j,N,temp,cnt = 0;//骑车的天数
    vector<int> dis(100000);//骑车的距离
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &temp);
        dis.push_back(temp);
    }
    sort(dis.begin(),dis.end(),cmp);//降序排序
    for(i = 0; i < N; ++i)//天数
    {
        if(dis[i] > i + 1)
            cnt++;
        else
            break;
    }
    printf("%d",cnt);
    dis.clear();
    return 0;
}





