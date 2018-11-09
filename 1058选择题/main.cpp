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
/*
输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：

按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。

输入样例：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4
*/
int count_all[100];

void show(const int &s)
{
    cout << s << endl;
}
int main()
{
    char op;
    int i,k,stu_num,pro_num;
 //   cout << "输入学生人数和多选题数:" << endl;
    cin >> stu_num >> pro_num;
    cin.get();
    vector<string> temp(pro_num);
    vector<string> a(pro_num);
    vector<int> ans(stu_num);
    vector<int> allansnum(pro_num);
    vector<int> lastans(pro_num);
    vector<int> selectnum(pro_num);
 //   cout << "依次输入满分值、选项个数、正确选项个数和正确的选项:" << endl;
    for(i = 0; i < pro_num; i++)
    {
      //  cout << "输入满分值和选项个数:";
        cin >> allansnum[i] >> selectnum[i];
        getchar();//缓冲
      //  cout << "正确选项个数和正确选项(字符串):" << endl;
        getline(cin,a[i]);//答案个数加答案选项
    }
    int sum,num;
    for(k = 0; k < stu_num; ++k){
            sum = 0;
        for(i = 0; i < pro_num; ++i){
            num = 0;
            scanf("%c",&op);
            if(op == '(')
            {
                getline(cin,temp[i],')');
                if(temp[i] == a[i])
                {
                    sum += allansnum[i];
                }
                else
                {
                    count_all[i]++;
                }
            }
            getchar();//缓冲
        }
        ans[k] = sum;
    }
    int max = -1,flag = 0,m = 0,l = 0,flag2 = 0;
    k = 0;
    for(i = 0; i < pro_num; ++i)
    {
        if(max < count_all[i])
        {
            max = count_all[i];
            m = i;
        }
    }
    for_each(ans.begin(),ans.end(),show);

    for(i = 0; i < pro_num; i++)
    {
        if(count_all[i] == max && max)
            k++;
    }
    if(k == 0)
        cout << "Too simple" << endl;
    else if(k == 1)//只有一个最大值
    {
        cout << max << " " << m + 1 << endl;
    }
    else
    {
        cout << max << " ";
        for(i = 0; i < pro_num; ++i)
        {
            if(count_all[i] == max && count_all[i])
            {
                if(k == 1)
                    cout << i + 1 << endl;
                else
                    cout << i + 1 << " ";
                --k;
            }
            else if(!count_all[i])
                flag = 1;
        }
        if(flag)
            cout << "Too simple" << endl;
    }
	return 0;
}









