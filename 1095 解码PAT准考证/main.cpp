#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string card;//准考证号
    int score = 0;//成绩
}student;
typedef pair<string, int> PAIR;
map< char,vector<student> > resLevel;
map<string,int> resScore,ScoreNum;
map< string,vector< student > > resYear;
map<string, map<string,int> > resY;

int cmp(student a,student b) {
    return a.score == b.score ? a.card < b.card : a.score >= b.score;
}
bool cmp_val(const PAIR &left,const PAIR &right)
{
    return left.second == right.second ? left.first < right.first : left.second >= right.second;
}


void printLevel(char level) {
    map< char,vector<student> >::iterator it = resLevel.find(level);
    if(it == resLevel.end()) {
        printf("NA\n");
        return;
    }
    vector<student> tmp = it->second;
    sort(tmp.begin(),tmp.end(),cmp);
    for(int i = 0; i < tmp.size(); i++) {
        cout << tmp[i].card << ' ' << tmp[i].score << endl;
    }
}



int main()
{
    int n,m,score;
    string card;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++) {
        cin >> card >> score;
        string no = card.substr(1,3);
        string year = card.substr(4,6);
        student tmp;
        tmp.card = card;
        tmp.score = score;
        resLevel[card[0]].push_back(tmp);
        resScore[no] += score;//由考场编号算出考场总分
        ScoreNum[no]++;
        resY[year][no]++;
        resYear[year].push_back(tmp);//由年月份算出考场编号和总人数
    }
    for(int i = 0; i < m; i++) {
        int num;
        scanf("%d",&num);
        if(num == 1) {
            char lev;
            getchar();
            scanf("%c",&lev);
            printf("Case %d: %d %c\n",i + 1,num,lev);
            printLevel(lev);
        } else if(num == 2) {
            string number;
            cin >> number;
            printf("Case %d: %d ",i + 1,num);
            cout << number << endl;
            if(resScore.find(number) == resScore.end()) {
                printf("NA\n");
            } else {
                cout << ScoreNum[number] << ' ' << resScore[number] << endl;
            }
        } else {
            string t;
            cin >> t;
            printf("Case %d: %d ",i + 1,num);
            cout << t << endl;
            map<string, map<string,int> >::iterator it = resY.find(t);
            if(it == resY.end()) {
                printf("NA\n");
            }else {
                map<string,int> tmp = it->second;
                vector<PAIR> vec(tmp.begin(),tmp.end());
                sort(vec.begin(),vec.end(),cmp_val);
                for(auto p = vec.begin(); p != vec.end(); p++) {
                    cout << p->first << ' ' << p->second << endl;
                }
            }

        }

    }
    return 0;
}
