#include <cstdio>
#include <cmath>
#include<ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <malloc.h>
#include <memory.h>
using namespace std;
/*
输入第1行给出3个正整数，
分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，


即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），
为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线L的考生也按总分排序，但排在第三类考生之后。


随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，
考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
*/
struct student{
    string id;
    int moral;
    int talent;
};

bool compare(const student s1,const student s2)//总结：当要进行排序的时候  只需要比较两个变量的大小：例子如下
{
    if(s1.moral + s1.talent == s2.moral + s2.talent)//总分相同
    {
        if(s1.moral == s2.moral)
        {
            return s1.id < s2.id;//id升序:左边小于右边代表升序
        }
        else
            return s1.moral > s2.moral;
    }
    return s1.moral + s1.talent > s2.moral + s2.talent;//降序排列:左边大于右边代表降序
}
void show(const student &iter)
{
    printf("%s %d %d\n",iter.id.c_str(),iter.moral,iter.talent);
//    cout << iter.id << ' ' << iter.moral << ' ' << iter.talent << endl;//超时
}

int main()
{
    vector<student> ans1,ans2,ans3,ans4;//结构体数组
    int N,L,H;
    int RightPeople = 0;
    student temp;
//    cin >> N >> L >> H;//超时
    scanf("%d%d%d",&N,&L,&H);
    int i;
    for(i = 1; i <= N; ++i)
    {
        cin >> temp.id;
        scanf("%d%d",&temp.moral,&temp.talent);
  //      cin >> temp.id >> temp.moral >> temp.talent;//超时
        getchar();
        if(temp.moral >= L && temp.talent >= L)//不低于最低分数线
        {
            if(temp.moral >= H && temp.talent >= H)//第一类:才德全尽
                ans1.push_back(temp);
            else if(temp.moral >= H && temp.talent < H)//第二类:德胜才
                ans2.push_back(temp);
            else if(temp.moral < H && temp.talent < H && temp.moral >= temp.talent)//第三类:才德兼亡并德胜才
                ans3.push_back(temp);
            else//其它达到最低分数线的
                ans4.push_back(temp);
            ++RightPeople;
        }
    }
    sort(ans1.begin(),ans1.end(),compare);
    sort(ans2.begin(),ans2.end(),compare);
    sort(ans3.begin(),ans3.end(),compare);
    sort(ans4.begin(),ans4.end(),compare);
    printf("%d\n",RightPeople);
    for_each(ans1.begin(),ans1.end(),show);//遍历
    for_each(ans2.begin(),ans2.end(),show);
    for_each(ans3.begin(),ans3.end(),show);
    for_each(ans4.begin(),ans4.end(),show);
	return 0;
}








