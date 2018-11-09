#include <bits/stdc++.h>
using namespace std;
struct node {
    int number = 0,rank,final_score = 0;
    double score = 0;
    string school;
};
int cmp(node a,node b) {
    if(a.final_score == b.final_score) {
        if(a.number == b.number) return a.school < b.school;
        return a.number < b.number;
    }
    return a.final_score > b.final_score;
}
int main() {
    int n;
    double score;
    scanf("%d",&n);
    getchar();
    vector<node> res;
    map<string,node> ans;
    for(int i = 0; i < n; ++i) {
        char name[10],school[10];
        scanf("%s %lf %s",name,&score,school);
        for(int j = 0; j < strlen(school); ++j) school[j] = tolower(school[j]);
        ans[school].number++;
        ans[school].school = school;
        if(name[0] == 'A' ) ans[school].score += score;
        else if(name[0] == 'T') ans[school].score += score * 1.5;
        else ans[school].score += score / 1.5;
    }
    for(auto it = ans.begin(); it != ans.end(); ++it) {
        node &t = it->second;
        t.final_score = (int)t.score;
        res.push_back(t);
    }
    sort(res.begin(),res.end(),cmp);
    for(int i = 0,k = 1; i < res.size(); ++i) {
        res[i].rank = k;
        if( i < res.size() - 1 && res[i].final_score > res[i+1].final_score) k = i + 2;
    }
    printf("%d\n",res.size());
    for(int i = 0; i < res.size(); ++i) printf("%d %s %d %d\n",res[i].rank,res[i].school.c_str(),res[i].final_score,res[i].number);
}
