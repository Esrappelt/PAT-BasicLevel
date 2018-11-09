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

//显示函数
void show(const vector<int> a)
{
    int i,n = a.size();
    for(i = 0; i < n; ++i)
    {
        cout << a[i];
        if(i < n - 1)
            cout << ' ';
    }
    cout << endl;
}
//判断函数
bool judge(const vector<int> a,const vector<int> b)
{
    int i,n = a.size();
    for(i = 0; i < n; ++i)
    {
        if(a[i] != b[i])
            return false;//比对失败
    }
    return true;//比对成功
}
//对于插入排序
bool Insert(const vector<int> x,const vector<int> y)
{
    int i,j,temp;
    vector<int> a(x),b(y);
    int n = a.size();
    for(i = 1; i < n; ++i)
    {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j+1] = a[j];
        a[j+1] = temp;
        //开始比对
        if(judge(a,b))//比对成功,再对b进行一轮插入排序
        {
            sort(b.begin(),b.begin()+ i + 2);
            cout << "Insertion Sort" << endl;
            show(b);
            return true;
        }
    }
    return false;
}

//对于归并排序
void Merge(const vector<int> x,const vector<int> y)
{
    vector<int> a(x),b(y);
    int i,n = a.size(),cnt = 1,flag = 1;
    while(flag)//比对成功就退出
    {
        flag = 0;
        if(!judge(a,b))//进行比对
            flag = 1;
        cnt  = cnt * 2;
        for(i = 0; i < n / cnt; ++i)//如果长度是偶数，则刚好是偶数对的归并，否则少一次,即最后一个数不会处理
            sort(a.begin()+ i * cnt,a.begin() + i * cnt + cnt);
        //然后如果长度是奇数，则还要处理一下最后一个数
        for( i = cnt * ( n / cnt); i < n; i++ ) // 对 非偶数序列进行排序
            sort( a.begin()+ cnt * (n / cnt ), a.begin() + n );
    }
    cout << "Merge Sort" << endl;
    show(a);
}
//主函数
int main()
{
    int N,i,temp,tag = 0;
    vector<int> a,b;//a是原序列,b是中间排序产生的序列
    cin >> N;
    for(i = 0; i < N; ++i)
    {
        cin >> temp;
        a.push_back(temp);
    }
    cin.clear();
    for(i = 0; i < N; ++i)
    {
        cin >> temp;
        b.push_back(temp);
    }
    if(Insert(a,b))
        tag = 1;
    if(!tag)
        Merge(a,b);//如果直接运行两个函数会出指针问题
	return 0;
}
//注释
/*
插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：

输入在第一行给出正整数N (<=100)；
随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：

首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；
然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。
输入样例1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
