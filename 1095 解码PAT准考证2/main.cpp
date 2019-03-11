#include <bits/stdc++.h>
using namespace std;
struct student{
    string card;//准考证号
    int score = 0;//成绩
    bool operator<(const student &tmp) const {
        return this->score != tmp.score ? this->score > tmp.score : this->card < tmp.card;
	}
};
int main()
{
    int n,m,score,num;
    string card,t;
    map< char,vector<student> > resLevel;
    map<string,int> resScore,ScoreNum;
    map<string,map<string,int>> resYear;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++) {
        cin >> card >> score;
        string no = card.substr(1,3),year = card.substr(4,6);
        student tmp;
        tmp.card = card,tmp.score = score;
        resLevel[card[0]].push_back(tmp);
        resScore[no] += score,ScoreNum[no]++;//由考场编号算出考场总分
        resYear[year][no]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> num >> t;
        printf("Case %d: %d ",i+1,num);
        cout << t << endl;
        if(num == 1) {
            if( resLevel.find(t[0]) != resLevel.end() ) {
                vector<student> tmp = resLevel[t[0]];
                sort(tmp.begin(),tmp.end());
                for(auto &it : tmp) printf("%s %d\n",it.card.c_str(),it.score);
            } else printf("NA\n");
        }
        else if(num == 2) {
            if(resScore.find(t) != resScore.end()) printf("%d %d\n",ScoreNum[t],resScore[t]);
            else printf("NA\n");
        } else {
            set<student> resY;
            for(auto &it: resYear[t]) {
                student s;
                s.card = it.first,s.score = it.second;
                resY.insert(s);
            }
            for(auto &it : resY) {
                printf("%s %d\n",it.card.c_str(),it.score);
            }
            if(!resY.size()) printf("NA\n");
        }
    }
    return 0;
}
