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

struct element{
    int address;
    int data;
    int nextaddress;
};

int main()
{
    int N,K,adr,i,j,first;
    vector<int> a(100000),next(100000);
    scanf("%05d%d%d",&first,&N,&K);//N是整数,K是基准,first是首地址
    int tmp = first;
    vector<element> ans(N);
    for(i = 0; i < N; ++i)
    {
        scanf("%05d",&adr);
        scanf("%d %05d",&a[adr],&next[adr]);//a数组装的是adr这个地址的值,b数组装的是这个值的下一个地址
    }
    if(N == 1)
    {
        printf("%05d %d -1\n",first,a[first]);
        return 0;
    }
    int temp = tmp,index = 0;
    for(j = 1; j <= 3; ++j)
    {
        temp = tmp;
        while(temp != -1)
        {
            if(a[temp] < 0 && j == 1)
            {
                ans[index].data = a[temp];
                ans[index].address = temp;
                index++;
            }
            else if(j == 2 && a[temp] >= 0 && a[temp] <= K)
            {
                ans[index].data = a[temp];
                ans[index].address = temp;
                index++;
            }
            else if(j == 3 && a[temp] > K)
            {
                ans[index].data = a[temp];
                ans[index].address = temp;
                index++;
            }
            temp = next[temp];
        }
    }
    for(i = 0; i < index; ++i)
    {
        if(i < index - 1)
            printf("%05d %d %05d\n",ans[i].address,ans[i].data,ans[i+1].address);
        else
            printf("%05d %d %d\n",ans[i].address,ans[i].data,-1);
    }
    return 0;
}
/*
输入格式：

每个输入包含1个测试用例。
每个测试用例第1行给出：第1个结点的地址；结点总个数，即正整数N (<= 105)；以及正整数K (<=1000)。
结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址；Data是该结点保存的数据，为[-105, 105]区间内的整数；Next是下一结点的地址。题目保证给出的链表不为空。

输出格式：

对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

*/
